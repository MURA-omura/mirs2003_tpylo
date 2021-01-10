# 各種ファイルの保存ディレクトリ
DIR_SRC  := ./src
DIR_HEAD := ./include
DIR_OBJ  := ./build

# 生成するプログラム
PRGS := tpylo
PRGS += test_follow test_io test_move test_straw test_uss

# オブジェクト
OBJS_RUN := $(addprefix $(DIR_OBJ)/, tpylo.o test_follow.o test_io.o test_move.o test_straw.o test_uss.o)
OBJS_UPS := $(addprefix $(DIR_OBJ)/, move.o straw.o ussmgr.o)
OBJS_STR := $(addprefix $(DIR_OBJ)/, arduino.o hand.o request.o spray.o)
OBJS_USS := $(addprefix $(DIR_OBJ)/, uss.o)
OBJS_UTL := $(addprefix $(DIR_OBJ)/, alternate.o io.o)
OBJS_ETC := $(addprefix $(DIR_OBJ)/, arcohol.o sock.o)

# コンパイルオプション
CC      := g++
CFLAGS  := -O2 -Wall -MMD -MP
LDFLAGS := -lm -lpthread -lwiringPi
INCLUDE := -I $(DIR_HEAD)

# 全コンパイル・ファイル削除用ターゲット
.PHONY: all clean

all: $(PRGS)

clean:
	$(RM) $(PRGS)
	$(RM) $(DIR_OBJ)/*.o $(DIR_OBJ)/*.d

# パターンルール
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@if [ ! -d $(DIR_OBJ) ]; then echo "mkdir $(DIR_OBJ)"; mkdir $(DIR_OBJ); fi
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	@if [ ! -d $(DIR_OBJ) ]; then echo "mkdir $(DIR_OBJ)"; mkdir $(DIR_OBJ); fi
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

# 依存関係ファイルの読み込み
-include $(DIR_OBJ)/*.d

# プログラム毎に生成ルールを記述
tpylo: $(OBJS_UPS) $(OBJS_STR) $(OBJS_USS) $(OBJS_UTL) $(OBJS_ETC) $(DIR_OBJ)/tpylo.o
	$(CC) $(LDFLAGS) $^ -o $@

test_follow: $(OBJS_UPS) $(OBJS_STR) $(OBJS_USS) $(OBJS_UTL) $(OBJS_ETC) $(DIR_OBJ)/test_follow.o
	$(CC) $(LDFLAGS) $^ -o $@

test_io: $(OBJS_UTL) $(DIR_OBJ)/test_io.o
	$(CC) $(LDFLAGS) $^ -o $@

test_move: $(OBJS_UPS) $(OBJS_STR) $(OBJS_USS) $(OBJS_UTL) $(OBJS_ETC) $(DIR_OBJ)/test_move.o
	$(CC) $(LDFLAGS) $^ -o $@

test_request: $(DIR_OBJ)/test_request.o
	$(CC) $(LDFLAGS) $^ -o $@

test_straw: $(OBJS_STR) $(OBJS_UTL) $(DIR_OBJ)/test_straw.o
	$(CC) $(LDFLAGS) $^ -o $@

test_uss: $(OBJS_USS) $(DIR_OBJ)/test_uss.o
	$(CC) $(LDFLAGS) $^ -o $@
