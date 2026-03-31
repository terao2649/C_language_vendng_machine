/*********************************************/
/*                                           		　　　*/
/*       プログラム名：自動販売機のプログラム            */
/*                                           　　　　　　　　　　　*/
/*       作成者：Win太郎                      	　　　　*/
/*       作成日：2023/03/01                   	　　　　*/
/*                                           	　　　　　　　　*/
/*********************************************/
#include <stdio.h>
#include <string.h>

#include "InventoryControl.h"		//商品登録


static DRINK g_list[MAX_ENTRY];		// 飲み物リスト
static int	 g_count = 0;			// 登録数（このファイル内のみからアクセス可能）

/*
 * 項目の位置を取得する
 */
int getIndex( const char* name ) {
	int i;
    for ( i = 0; i < g_count; i++) {
        if ( !strcmp( g_list[i].name, name ) ) {
            return i;
        }
    }
    return -1;
}
/**
 * 商品登録
 */
 void inv_add( DRINK drink ){
 	if( g_count >= MAX_ENTRY ){
		printf( "これ以上登録できません。\n" );
		return ;
	}
	if( getIndex(drink.name) != -1 ){
		printf( "%sは既に登録されています。\n", drink.name);
		return ;
	}
	g_list[g_count] = drink;		//登録
	g_count++;
}

 /*
void inv_add( enum DrinkKind type, const char* goodsName, int price, const char* note ){
	if( g_count >= MAX_ENTRY ){
		printf( "これ以上登録できません。\n" );
		return ;
	}
	if( getIndex(goodsName) != -1 ){
		printf( "%sは既に登録されています。\n", goodsName);
		return ;
	}
	g_list[g_count].type = type;				// 種類（COFFEE, WATER, TEA）
	strcpy( g_list[g_count].name, goodsName );	// 名前
	g_list[g_count].price = price;				// 値段
	strcpy( g_list[g_count].note, note);		// 特記事項
	g_count++;

}
*/
// 在庫
void addStock( const char* name, int amount ){
    int idx = getIndex(name);

    if( idx == -1){
   		printf( "%sが見つかりません。\n", name );
    	return;
    }
    g_list[idx].stock += amount;

    return;

}

//　初期在庫数設定
void inv_setInitStock( int amount ){
	int i;
	for (i = 0; i < g_count; i++) {
		g_list[i].stock = amount;	//初期在庫数設定
    }
}
//　商品一覧表示
void inv_dispGoodsList(  ){
	
	char temp[30];
	int i;

   	printf("\n");
	printf("◆◆ 商品表示 ◆◆\n");
	
	for (i = 0; i < g_count; i++) {
    	
		//商品の品名と金額を表示する
		printf("\n");
    	printf("(%d) %s", i+1, g_list[i].name );
        printf(" \t%d円\n", g_list[i].price );
       
		//特記事項 表示
        switch( g_list[i].type ){
        case COFFEE:
        	strcpy( temp, "豆原産地：");
        	break;
        case WATER:
        	strcpy( temp, "採水地：" );
        	break;
        case TEA:
        	strcpy( temp, "種類：" );
        	break;
        default:
        	;
        }

        strcat( temp, g_list[i].note );

        printf(" （ %s ）\n", temp );
	
	}
	
	printf("\n");

}

// 商品購入
int inv_buying(int money, int goodsNo ) {

	int stock;
	int price;

	//在庫の数を取得する
	stock = g_list[goodsNo-1].stock;
	
	//在庫があるかどうかの判定
	if( stock <= 0 ){
		printf("\n在庫がありません。\n");
		return -1;
	}

	//商品の金額を取得する
	price = g_list[goodsNo-1].price;
	
	//お金が足りているかの判定
	if( money < price ){
		printf("\nお金が不足しています。\n");
		return -1;
	}
	
	g_list[goodsNo-1].stock--;
	printf( "\n【%s】を購入しました。", g_list[goodsNo-1].name);
	
	return money-price;
}

// 在庫表示
void inv_dispStockList(  ){

	int i;
   	
	//在庫のある商品を表示する
	printf("\n");
	printf("◆◆ 商品在庫 ◆◆\n");
	for (i = 0; i < g_count; i++) {
    	printf("\n");
    	printf("(%d) %s ・・・・%d本\n", i+1, g_list[i].name, g_list[i].stock );
    }
   	
	printf("\n");
}

