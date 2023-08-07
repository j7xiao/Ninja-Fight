# ----------------------------
# Makefile Options
# ----------------------------

NAME = NINJAFGT
ICON = icon.png
DESCRIPTION = "NInja Fight!"
COMPRESSED = YES
ARCHIVED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)