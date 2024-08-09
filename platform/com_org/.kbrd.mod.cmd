savedcmd_/home/siddu/platform/com_org/kbrd.mod := printf '%s\n'   kbrd.o | awk '!x[$$0]++ { print("/home/siddu/platform/com_org/"$$0) }' > /home/siddu/platform/com_org/kbrd.mod
