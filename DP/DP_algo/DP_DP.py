# coding: utf-8
# 実行環境はとりあえずpython2.X系でnumpyが使える環境

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
            weight_data.append(map(int,items))

    return (max_weight, weight_data)

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

    # print(C)

    for w in range(max_weight+1):
        G[0][w] = TOP

    for i in xrange(1,data_len+1):
        weight = weight_data[i-1][WEIGHT]
        value = weight_data[i-1][VALUE]
        for j in xrange(1,max_weight+1):
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

    #print("map")
    #for c in C:
    #    for num in c:
    #        print("%2d " % num),
    #    print("")


    ## この辺からとても微妙
    ## 0-1のペアの作り方が謎
    #print("dialog")
    #for c in G:
    #    for num in c:
    #        print("%2d " % num),
    #    print("")

    ## 配列を逆順に
    #i = 0
    #for c in G:
    #    G[i].reverse()
    #    i += 1
    #G.reverse()

    #print("dialog_1")
    #for c in G:
    #    for num in c:
    #        print("%2d " % num),
    #    print("")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("python DP_DP.py [FILE_NAME]")
        sys.exit(-1)

    FILE_NAME = sys.argv[1]
    file_data = read_data(FILE_NAME)

    print("max_weight: %d" % file_data[0])
    print("data_len : %d" % len(file_data[1]))

    # dp( max_weight, weight_data)
    dp(file_data[0], file_data[1])

    print("end calc")
