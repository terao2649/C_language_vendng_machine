/*
 * 自動販売機の購入
 * 修正者：菅
 * 修正日：2026/03/31
 */

#include <stdio.h>

#include "Drink.h"
#include "VendingMachin.h"
#include "InventoryControl.h"


/*
 * プロトタイプ宣言
 */

/* VendingMachin */
int  inputString(const char* prompt);
void inputEnter(const char* prompt);
int  getMoneyFromCustomer( void );
void setMoneyFromCustomer(int money);
void buying( void );

static int g_moneyFromCustomer = 0;	//お客から預かったお金

/**
 * 自動販売機のシステム
 */
int main( void )
{
	DRINK drink[] = {
		{COFFEE, "BOSS RAINBOW", "", 130, 1, 200, INIT_STOCK, "コロンビア"},
		{COFFEE, "BOSS PREMIUM", "", 130, 1, 200, INIT_STOCK, "グアテマラ"},
		{WATER, "エ ビ ア ン", "", 100, 1, 350, INIT_STOCK, "フランス"},
		{WATER, "おいしい天然水", "", 130, 1, 500, INIT_STOCK, "富士山麓"},
		{TEA, "綾鷹 あやたか", "", 130, 1, 500, INIT_STOCK, "緑茶"},
		{TEA, "爽 健 美 茶", "", 130, 1, 500, INIT_STOCK, "ブレンド茶"}
	};
	int i;

	setvbuf(stdout, NULL, _IONBF, 0);

	for( i = 0; i < 6; i++ ){
		inv_add( drink[i] );
	}

	inv_setInitStock( INIT_STOCK );//初期在庫設定

	do{
		 int no;

		 printf("\n\n◆◆　操作メニュー　◆◆\n");		//操作メニューの表示
		 printf("\n(1) 商品を購入する\n");		//選択肢1の表示
		 printf("\n(2) 在庫を確認する\n");		//選択肢2の表示
		 printf("\n(3) 終了\n");				//選択肢3の表示
		 no = inputString("\n番号を入力してください。>");//番号入力依頼の表示

		 switch( no ){
			case 1:
				inv_dispGoodsList();
				buying();
			break;
			case 2:
				inv_dispStockList();
				inputEnter("\n表示を確認してください。[Enter]>");
			break;
			case 3:
			return 0;
		 }
	}while(1);
}
/*
 * 商品を購入する
 */
void buying( )
{
	int input = 0;	//投入金額
	int temp;		//作業用
	int goods;		//商品番号
	int change;		//おつり

	while( 1 ){
		temp = inputString("\nお金を投入してください。 >");
		input += temp;
		setMoneyFromCustomer( input );

		temp = inputString("\n商品を選んでください。>");
		goods = temp;

		//商品購入
		change = inv_buying(getMoneyFromCustomer(), goods);

		if( change < 0 )	continue;

		setMoneyFromCustomer(input-change); //自販機のお金を減額
		printf("\nおつりは");
		if( change != 0 ){
			printf( "%d円です。\n", change );
			inputEnter("\n商品とおつりをお取りください。[Enter]>");
		}
		else {
			printf( "ありません。\n");
			inputEnter("\n商品をお取りください。[Enter]>");
		}
		break;
	}

}
/*
 * 文字列を入力する
 */
int inputString(const char* prompt){
	int line;

    printf("%s", prompt);

    scanf("%d", &line );

    return line;
}
/*
 * Enterキーを入力する
 */
void inputEnter( const char* prompt ) {


    printf("%s", prompt);

    fflush(stdin);	//バッファ

    getc(stdin);
}
int getMoneyFromCustomer() {
	return g_moneyFromCustomer;
}

void setMoneyFromCustomer(int money) {
	g_moneyFromCustomer = money;
}



