並列計算とか扱ってみた

## 環境
学校 OpenMP, Intel MPI
自宅 OpenMP, OpenMPI

## 構成
#### MPI/
MPI関連(メモリ非共有)
複数のPCをつないだり、プロセスとして分割する。

#### OpenMP/
OpenMP関連(メモリ共有)
簡単に言えば、同じCPU,同じPC内で完結する。

- OpenMP
	- test1
		- OpenMPのバージョン確認
	- test2
		- 適当にforの並列化
	- test3
		- 各スレッドで1000ループ
		- それの足し合わせとか。スコープみたいな話
	- test4
		- システムの要件
		- 使えるスレッドの数とか
	- test_loop
		- sum += i;を大量にやる
		- 並列化とそうでないものの違いを見る
		- test_loop.hが必要
	- test_s_loop
		- sum += i;のシングルスレッド版
		- test_loop.hが必要
	- my_test1
		- 乱数がプロセスごとに別に生成されるかの確認
		- 無事に別々に生成された