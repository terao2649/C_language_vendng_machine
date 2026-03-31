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

 /* 飲み物を追加する関数*/
void inv_add( DRINK drink );
//void inv_add( enum DrinkKind type, const char* goodsName, int price, const char* note );
 /* 販売品リスト追加する関数*/
void inv_dispGoodsList( void );
 /* 在庫リスト追加する関数 */
void inv_dispStockList( void );
 /* お金とグッズの定義追加する関数 */
int  inv_buying( int money, int goodsNo );
 /* 在庫数の設定追加する関数 */
void inv_setInitStock( int stockNum );


#endif
