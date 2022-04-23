__int64 __fastcall be::check_csrss_integrity(__int64 a1, unsigned __int64 a2, unsigned int a3, unsigned __int64 a4, unsigned int a5)
{
  __int64 v6; // r12
  __int64 result; // rax
  __int64 v10; // rdi
  __int64 v11; // rdx
  unsigned int v12; // er8
  __int64 v13; // rax
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rax
  __int64 v16; // rbx
  int v17; // edx
  unsigned __int64 v18; // rsi
  __int128 *v19; // rcx
  char v20; // [rsp+20h] [rbp-91h] BYREF
  int v21; // [rsp+21h] [rbp-90h]
  __int64 v22; // [rsp+25h] [rbp-8Ch]
  __int128 v23; // [rsp+2Dh] [rbp-84h]
  __int128 v24; // [rsp+3Dh] [rbp-74h]
  __int128 v25; // [rsp+4Dh] [rbp-64h]
  __int128 v26; // [rsp+5Dh] [rbp-54h]
  char v27[48]; // [rsp+70h] [rbp-41h] BYREF
  char v28[16]; // [rsp+A0h] [rbp-11h] BYREF
  __m128i v29; // [rsp+B0h] [rbp-1h] BYREF
  int v30; // [rsp+C0h] [rbp+Fh]
  int v31; // [rsp+C4h] [rbp+13h]
  int v32; // [rsp+C8h] [rbp+17h]

  v6 = a3;
  strcpy(v28, "csrss.exe");
  result = sub_1403440C2(v28, 0i64);
  v10 = result;
  if ( result )
  {
    KeStackAttachProcess(result, v27);
    v11 = (__int64)&v29;
    v29 = _mm_load_si128(&unk_1400140E0);
    v30 = 0x8DAB8D90;
    v12 = 0;
    v32 = 0xFF928D90;
    v31 = 0x998C919E;
    do
    {
      *(_BYTE *)v11 = ~*(_BYTE *)v11;
      ++v12;
      ++v11;
    }
    while ( v12 < 28 );
    v13 = resolve(a1, (__int64)&v29);
    v14 = v13;
    if ( v13 )
    {
      v15 = v13 + 16;
      while ( v14 < v15 )
      {
        if ( *(_WORD *)v14 == 0x8B48
          && *(_BYTE *)(v14 + 2) == 5
          && *(_DWORD *)(v14 + 7) == 0x74C08548
          && *(_WORD *)(v14 + 12) == 0x15FF )
        {
          v16 = 0i64;
          v17 = 0;
          v18 = *(unsigned int *)(v14 + 3) + v14;
          while ( 1 )
          {
            v19 = *(__int128 **)(v18 + 8 * v16 + 7);
            if ( v19 )
            {
              if ( a2 <= (unsigned __int64)v19 && (unsigned __int64)v19 < v6 + a2
                || a4 <= (unsigned __int64)v19 && (unsigned __int64)v19 < a5 + a4 )
              {
                v17 = 0;
              }
              else
              {
                v22 = *(_QWORD *)(v18 + 8 * v16 + 7);
                v20 = 0x21;
                v21 = v16;
                v23 = *v19;
                v24 = v19[1];
                v25 = v19[2];
                v26 = v19[3];
                be::report((__int64)&v20, 77i64);
                v17 = 0;
              }
            }
            else if ( ++v17 == 3 )
            {
              goto LABEL_22;
            }
            v16 = (unsigned int)(v16 + 1);
          }
        }
        ++v14;
      }
    }
LABEL_22:
    KeUnstackDetachProcess(v27);
    PsReleaseProcessExitSynchronization(v10);
    result = ObfDereferenceObject(v10);
  }
  return result;
}