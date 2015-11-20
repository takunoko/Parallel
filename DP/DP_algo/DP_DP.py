# coding: utf-8
# 実行環境はとりあえずpython3.X系でnumpyが使える環境

# 動的計画法を用いた0-1ナップサック問題
# 参考URL : http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=DPL_1_B
# この手法でO(NW)で最適解を求めることができる。

# 5J授業、ドラゴンポールに適応したプログラム

import sys
import re

def read_data(FILE_NAME):
    max_weight = 0      # 最大容量
    weight_data = []    # 重さの配列データ

    f = open(FILE_NAME, 'r')
    lines = f.readlines()
    for line in lines:
        items = re.split(r',|=',line)
        if len(items) < 3 or items[0] == "number":
            if items[0] == "limit": # 1行目の処理
                max_weight = int(items[1])
                print("limit = %d" % max_weight);
            else: # その他の行もとりあえず出力
                print(line),
        else:   # データが入っている行について
            print("%d, %d, %d" % (int(items[0]), int(items[1]), int(items[2])))
            weight_data.append(list(map(int,items)))

    return (max_weight, weight_data)

# ,で区切られたN番目(0から開始)がどのデータに対応するか
# INDEX=0
VALUE=1
WEIGHT=2

# 品物を使った時: DIALOG
# 使わなかった時: TOP
TOP=0
DIALOG=1

def dp(max_weight, weight_data):
    data_len = len(weight_data)
    C = [[0 for i in range(max_weight+1)] for j in range(data_len+1)]
    G = [[0 for i in range(max_weight+1)] for j in range(data_len+1)]

    for w in range(max_weight+1):
        G[0][w] = TOP

    for i in range(1,data_len+1):
        weight = weight_data[i-1][WEIGHT]
        value = weight_data[i-1][VALUE]
        for j in range(1,max_weight+1):
            red_val = 0
            # 赤色斜め矢印
            if j-weight > 0:
                # 赤色矢印の左上の値
                red_val = C[i-1][j-weight]

            if weight <= j:
                red_val += value
                G[i][j] = DIALOG

            if C[i-1][j] < red_val:
                C[i][j] = red_val
                if G[i][j] == DIALOG:
                    G[i][j] = DIALOG
                else:
                    G[i][j] = TOP
            else:
                C[i][j] = C[i-1][j]
                G[i][j] = TOP

    # print("map")
    # for c in C:
    #     for num in c:
    #         print("%2d " % num),
    #     print("")


    # print("dialog")
    # for c in G:
    #     for num in c:
    #         print("%2d " % num),
    #     print("")

    # 逆順に答えをたどる
    # comb は1/0のペア
    j = max_weight
    weight = 0
    comb = []
    for i in range(data_len, 0, -1):
        if G[i][j] == 1:
            j -= weight_data[i-1][WEIGHT]
            weight += weight_data[i-1][WEIGHT]
            comb.append(1)
        else:
            comb.append(0)
        if j < 0:
            break;

    comb.reverse()

    return (comb, C[data_len][max_weight], weight)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("python DP_DP.py [FILE_NAME]")
        sys.exit(-1)

    FILE_NAME = sys.argv[1]
    file_data = read_data(FILE_NAME)

    # dp( max_weight, weight_data)
    comb = dp(file_data[0], file_data[1])

    print("\nvalue : %d | weight : %d" % (comb[1], comb[2]))
    print('combination: ')
    for c in comb[0]:
        print("%d" % (c),end="")

    print("\nend calc")
