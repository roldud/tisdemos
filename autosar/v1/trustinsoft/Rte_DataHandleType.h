#ifndef RTE_DATA_HANDLE_TYPE_H
#define RTE_DATA_HANDLE_TYPE_H

typedef struct
{
    sint16 value;
}
Rte_DE_sint16;

typedef struct
{
    sint16 value;
    Std_ReturnType status;
}
Rte_DES_sint16;

typedef struct
{
    sint16 value;
    Std_ReturnType status;
    Std_ReturnType feedback;
}
Rte_DEX_sint16;

typedef struct
{
    sint32 value;
}
Rte_DE_sint32;

typedef struct
{
    sint32 value;
    Std_ReturnType status;
}
Rte_DES_sint32;

typedef struct
{
    sint32 value;
    Std_ReturnType status;
    Std_ReturnType feedback;
}
Rte_DEX_sint32;


#endif /* RTE_DATA_HANDLE_TYPE_H */
