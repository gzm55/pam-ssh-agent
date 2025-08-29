// ref: https://chromium.googlesource.com/external/github.com/google/protobuf/+/HEAD/ruby/ext/google/protobuf_c/wrap_memcpy.c

#include <string.h>
#include <spawn.h>
#define restrict

#ifdef __linux__
#if defined(__x86_64__) && defined(__GNU_LIBRARY__)

__asm__(".symver memcpy,memcpy@GLIBC_2.2.5");
void *__wrap_memcpy(void *dest, const void *src, size_t n)
{ return memcpy(dest, src, n); }

__asm__(".symver posix_spawnp,posix_spawnp@GLIBC_2.2.5");
int __wrap_posix_spawnp(pid_t *restrict pid, const char *restrict file, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict], char * const envp[restrict])
{ return posix_spawnp(pid, file, file_actions, attrp, argv, envp); }

#else

void *__wrap_memcpy(void *dest, const void *src, size_t n)
{ return memmove(dest, src, n); }

int __wrap_posix_spawnp(pid_t *restrict pid, const char *restrict file, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict], char * const envp[restrict])
{ return posix_spawnp(pid, file, file_actions, attrp, argv, envp); }

#endif
#endif
