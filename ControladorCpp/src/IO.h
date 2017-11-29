/*
* IO.h
*
* Created: 29/11/2017 13:53:34
* Author: cuki
*/


#ifndef __IO_H__
#define __IO_H__

class IO
{
	uint8_t m_estado;

	public:
	IO();
	~IO();
	void teste_saidas(void);
	private:
	IO( const IO &c );
	IO& operator=( const IO &c );
	void clear_all(void);
}; //IO

#endif //__IO_H__
