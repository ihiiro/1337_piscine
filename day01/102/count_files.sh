#!/bin/bash

expr "$(tree | wc -l)" - 2
