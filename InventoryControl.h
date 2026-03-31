/**
 * InventoryControl.h
 */
#ifndef __INVENTORYCONTROL_H__
#define __INVENTORYCONTROL_H__

#include "VendingMachin.h"
#include "Drink.h"


/*
 * プロトタイプ宣言
 */

 /* InventoryControl */
void inv_add( DRINK drink );
//void inv_add( enum DrinkKind type, const char* goodsName, int price, const char* note );
void inv_dispGoodsList( void );
void inv_dispStockList( void );
int  inv_buying( int money, int goodsNo );
void inv_setInitStock( int stockNum );


#endif
