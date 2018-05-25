#include "percentimetro.h"
#include "timers.h"

#include <stdbool.h>

#define RELE		B,0
#define TIMER_STEP	10

static volatile bool m_ligado = false;
static volatile uint16_t m_periodo = 200;
static volatile uint16_t m_duty = 50;
static volatile uint16_t tempo_ligado = 100;
static volatile uint16_t tempo_desligado = 100;
static volatile uint16_t m_tick = 0;

void run(void)
{
	if (m_ligado)
	{
		if (m_tick == tempo_ligado)
		{
			m_tick = 0;
			m_ligado = false;
			RESET(RELE);
		}
	}
	else
	{
		if (m_tick == tempo_desligado)
		{
			m_tick = 0;
			m_ligado = true;
			SET(RELE);
		}
	}
	
	++m_tick;
}

void calculate_timer(void)
{
	if (m_duty == 0)
	{
		m_duty = 50;
	}
	
	if (m_periodo == 0)
	{
		m_periodo = 2000;
	}
	
	tempo_ligado = (uint16_t) ((float) m_duty / 100 * m_periodo);
	
	if (tempo_ligado > m_periodo)
	{
		m_periodo = 2 * tempo_ligado;
	}
	
	tempo_desligado = m_periodo - tempo_ligado;
	m_tick = 0;
}

void percentimetro_init(void)
{
	m_tick = 0;
	
	SET_OUTPUT(RELE);
	
	timer_1_setCallBack(&run);
	timer_1_stop();
}

void percentimetro_set_periodo(uint16_t periodo)
{
	if (periodo != 0 && periodo <= 2000)
	{
		m_periodo = periodo;
	}
	else
	{
		m_periodo = 2000;
	}
	
	calculate_timer();
}

void percentimetro_set_duty(uint16_t duty)
{
	if (duty == 0 || duty > 100)
	{
		m_duty = 50;
	}
	else
	{
		m_duty = duty;
	}
	
	calculate_timer();
}

void percentimetro_start(void)
{
	m_ligado = true;
	m_tick = 0;
	SET(RELE);
	timer_1_init(TIMER_STEP, F_CPU);
}

void percentimetro_stop(void)
{
	m_ligado = false;
	m_tick = 0;
	RESET(RELE);
	timer_1_stop();
}