/*
* IO.h
*
* Created: 29/11/2017 13:53:34
* Author: cuki
*/


#ifndef __IO_H__
#define __IO_H__

enum ENTRADAS
{
	IO_I0,
	IO_I1,
	IO_I2,
	IO_I3,
	IO_I4,
	IO_I5,
	IO_I6,
	IO_I7
};

enum SAIDAS
{
	IO_Q0,
	IO_Q1,
	IO_Q2,
	IO_Q3,
	IO_Q4,
	IO_Q5,
	IO_Q6,
	IO_Q7
};

class IO
{
	uint8_t m_estado;
	
	IO(const IO &c);
	IO& operator=(const IO &c);
	void clear_all(void);

	public:
	IO();
	~IO();
	void teste_saidas(void);
	uint8_t get_estado(void);
	bool get_entrada(enum ENTRADAS entrada);
	bool get_saida(enum SAIDAS saida);
	void set_saida(enum SAIDAS saida, bool val);

}; //IO

#endif //__IO_H__
