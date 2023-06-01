#!/bin/bash

ifconfig | grep -Po "(?:[0-9a-fA-F]{2}\:){5}[0-9a-fA-F]{2}" --color=never
