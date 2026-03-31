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

 /* 飲み物 */
void inv_add( DRINK drink );
//void inv_add( enum DrinkKind type, const char* goodsName, int price, const char* note );
 /* 販売品リスト */
void inv_dispGoodsList( void );
 /* 在庫リスト */
void inv_dispStockList( void );
 /* お金とグッズの定義 */
int  inv_buying( int money, int goodsNo );
 /* 在庫数の設定 */
void inv_setInitStock( int stockNum );


#endif
