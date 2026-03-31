/**
 *    Drink.h
 */
#ifndef __DRINK_H__
#define __DRINK_H__

enum DrinkKind { COFFEE, WATER, TEA };

typedef struct {
	enum DrinkKind	type;	// 種類（COFFEE, WATER, TEA）
	char		name[30];	// 名前
	char		maker[30];	// メーカー
	int			price;		// 値段
	int			cold;	    // 冷温（1:Cold,0:Hot）
	int			qty;		// 水量（ml）
	int			stock;		// 在庫
	char		note[30];	// 特記事項
}DRINK;

#endif

