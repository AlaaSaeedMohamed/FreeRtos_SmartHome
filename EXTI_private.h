#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_MCUCR *((volatile u8*)0x55)

#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#define EXTI_GICR  *((volatile u8*)0x5B)

#define GICR_INT0   6
#define GICR_INT1   7
#define GICR_INT2   5



#endif
