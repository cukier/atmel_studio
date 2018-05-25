#include "percentimetro.h"
#include "timers.h"

#include <stdbool.h>

#define RELE B,0

static volatile bool m_ligado = false;
static volatile uint16_t m_periodo = 20000;
static volatile uint16_t m_duty = 50;
static volatile uint16_t tempo_ligado = 10000;
static volatile uint16_t tempo_desligado = 10000;

void run(void)
{
	if (m_ligado)
	{
		m_ligado = false;
		RESET(RELE);
		timer_1_init(tempo_desligado, F_CPU);
	}
	else
	{
		m_ligado = true;
		SET(RELE);
		timer_1_init(tempo_ligado, F_CPU);
	}
}

void calculate_timer(void)
{
	if (m_duty == 0)
	{
		m_duty = 50;
	}
	
	if (m_periodo == 0)
	{
		m_periodo = 20;
	}
	
	tempo_ligado = (uint16_t) ((float) m_duty / 100 * m_periodo);
	
	if (tempo_ligado > m_periodo)
	{
		m_periodo = 2 * tempo_ligado;
	}
	
	tempo_desligado = m_periodo - tempo_ligado;
}

void percentimetro_init(void)
{
	SET_OUTPUT(RELE);
	
	timer_1_setCallBack(&run);
	timer_1_stop();
}

void percentimetro_set_periodo(uint16_t periodo)
{
	if (periodo > 1000)
	{
		m_periodo = periodo;
	}
	else
	{
		m_periodo = 20000;
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
	SET(RELE);
	timer_1_init(tempo_ligado, F_CPU);
}

void percentimetro_stop(void)
{
	m_ligado = false;
	RESET(RELE);
	timer_1_stop();
}
