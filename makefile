CC=gcc
CFLAGS=-c -std=c99 
OUTPUT=ls_by_nik

all: backup_ls.h backup_ls.c
	$(CC) backup_ls.h backup_ls.c -o $(OUTPUT)
