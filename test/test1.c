#include <stdio.h>
#include "miniz.h"

int doZip()
{
}

int main()
{
    static const char *s_pStr = "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson."
                                "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson."
                                "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson."
                                "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson."
                                "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson."
                                "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson."
                                "Good morning Dr. Chandra. This is Hal. I am ready for my first lesson.";
    int cmp_status;                         // 压缩状态
    uLong src_len = (uLong)strlen(s_pStr);  // 源字符串长度
    uLong cmp_len = compressBound(src_len); // 压缩长度
    uLong uncomp_len = src_len;             // 解压长度
    unsigned char *pCmp, *pUncomp;          // 压缩和解压缓冲区指针

    // 分配空间
    pCmp = (mz_uint8 *)malloc((size_t)cmp_len);
    pUncomp = (mz_uint8 *)malloc((size_t)src_len);
    if ((!pCmp) || (!pUncomp))
    {
        printf("Out of memory!\n");
        return EXIT_FAILURE;
    }

    // 压缩
    cmp_status = compress(pCmp, &cmp_len, (const unsigned char *)s_pStr, src_len);
    if (cmp_status != Z_OK)
    {
        printf("compress() failed!\n");
        free(pCmp);
        free(pUncomp);
        return EXIT_FAILURE;
    }
    printf("Compressed from %u to %u bytes\n", (mz_uint32)src_len, (mz_uint32)cmp_len);

    // 解压
    cmp_status = uncompress(pUncomp, &uncomp_len, pCmp, cmp_len);
    if (cmp_status != Z_OK)
    {
        printf("uncompress failed!\n");
        free(pCmp);
        free(pUncomp);
        return EXIT_FAILURE;
    }
    printf("Decompressed from %u to %u bytes\n", (mz_uint32)cmp_len, (mz_uint32)uncomp_len);

    return 0;
}