dnl    SPDX-FileCopyrightText: 2024 Monaco F. J. <monaco@usp.br>
dnl    SPDX-FileCopyrightText: 2024 hugoferreirj <huugo.vieira49@gmail.com>
dnl   
dnl    SPDX-License-Identifier: GPL-3.0-or-later
dnl
dnl  This file is a derivative work from SYSeg (https://gitlab.com/monaco/syseg)
dnl  and contains modifications carried out by the following author(s):
dnl  hugoferreirj <huugo.vieira49@gmail.com>

include(docm4.m4)dnl

##
## Relevant rules.


## 
## Rules used by SYSeg.
## Not relevant for the example.
##

EXPORT_FILES = README Makefile decode libcry.so
EXPORT_NEW_FILES = NOTEBOOK
DOCM4_EXPORT([imf],[1.0.0])
DOCM4_UPDATE
