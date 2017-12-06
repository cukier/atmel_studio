/* 
* AbstractRegister.h
*
* Created: 05/12/2017 16:33:04
* Author: cuki
*/


#ifndef __ABSTRACTREGISTER_H__
#define __ABSTRACTREGISTER_H__

#include <stdint.h>

class AbstractRegister
{
public:
	virtual AbstractRegister(uint16_t reg) = 0;
	virtual ~AbstractRegister();
	virtual void setRegister(uint16_t val);
	virtual uint16_t getRegister(void);

}; //AbstractRegister

#endif //__ABSTRACTREGISTER_H__
