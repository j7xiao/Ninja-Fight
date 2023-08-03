# ----------------------------
# Makefile Options
# ----------------------------

NAME = STKNINJA
ICON = icon.png
DESCRIPTION = "Stick Ninja!"
COMPRESSED = YES
ARCHIVED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)