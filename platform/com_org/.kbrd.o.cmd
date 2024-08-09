savedcmd_/home/siddu/platform/com_org/kbrd.o := gcc -Wp,-MMD,/home/siddu/platform/com_org/.kbrd.o.d  -nostdinc -I./arch/x86/include -I./arch/x86/include/generated  -I./include -I./arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/compiler-version.h -include ./include/linux/kconfig.h -include ./include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=./= -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -fcf-protection=branch -fno-jump-tables -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -mfunction-return=thunk-extern -fno-jump-tables -fpatchable-function-entry=16,16 -fno-delete-null-pointer-checks -O2 --param=allow-store-data-races=0 -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-stack-clash-protection -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -falign-functions=16 -fno-strict-overflow -fno-stack-check -fconserve-stack -Wall -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=1024 -Wno-main -Wvla -Wno-pointer-sign -Wcast-function-type -Wno-stringop-overflow -Wno-array-bounds -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wextra -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-type-limits -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter -g  -fsanitize=bounds-strict -fsanitize=shift -fsanitize=bool -fsanitize=enum  -fsanitize=signed-integer-overflow  -DMODULE  -DKBUILD_BASENAME='"kbrd"' -DKBUILD_MODNAME='"kbrd"' -D__KBUILD_MODNAME=kmod_kbrd -c -o /home/siddu/platform/com_org/kbrd.o /home/siddu/platform/com_org/kbrd.c   ; ./tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --ibt --retpoline --rethunk --stackval --static-call --uaccess --prefix=16  --link  --module /home/siddu/platform/com_org/kbrd.o

source_/home/siddu/platform/com_org/kbrd.o := /home/siddu/platform/com_org/kbrd.c

deps_/home/siddu/platform/com_org/kbrd.o := \
  include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/UBSAN_SIGNED_WRAP) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  include/linux/compiler_attributes.h \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/MITIGATION_RETPOLINE) \
    $(wildcard include/config/GCC_ASM_GOTO_OUTPUT_WORKAROUND) \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \

/home/siddu/platform/com_org/kbrd.o: $(deps_/home/siddu/platform/com_org/kbrd.o)

$(deps_/home/siddu/platform/com_org/kbrd.o):

/home/siddu/platform/com_org/kbrd.o: $(wildcard ./tools/objtool/objtool)
