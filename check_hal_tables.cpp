_DWORD *__fastcall be::check_hal_tables(unsigned __int64 a1, unsigned int a2, unsigned __int64 a3, unsigned int a4, unsigned __int64 a5, unsigned int a6, unsigned __int64 a7, unsigned int a8)
{
  __int64 v9; // r13
  __m128i *v11; // r9
  unsigned int v12; // er10
  __int64 v13; // rax
  unsigned __int64 *v14; // rdi
  unsigned int v15; // ebx
  unsigned int v16; // esi
  bool v17; // r15
  unsigned __int64 v18; // rcx
  __int64 v19; // rcx
  unsigned int v20; // edx
  _DWORD *result; // rax
  unsigned int v22; // ecx
  unsigned int v23; // esi
  unsigned int v24; // edi
  unsigned __int64 *v25; // rbx
  char v26; // al
  unsigned __int64 v27; // rcx
  bool v28; // r15
  char v30; // [rsp+30h] [rbp-79h] BYREF
  unsigned int v31; // [rsp+31h] [rbp-78h]
  unsigned __int64 v32; // [rsp+35h] [rbp-74h]
  __m128 Dst; // [rsp+3Dh] [rbp-6Ch] BYREF
  __int128 v34; // [rsp+4Dh] [rbp-5Ch]
  __int128 v35; // [rsp+5Dh] [rbp-4Ch]
  __int128 v36; // [rsp+6Dh] [rbp-3Ch]
  __m128i v37; // [rsp+80h] [rbp-29h] BYREF
  int v38; // [rsp+90h] [rbp-19h]
  int v39; // [rsp+94h] [rbp-15h]
  __m128i _HalDispatchTable; // [rsp+98h] [rbp-11h] BYREF
  char v41; // [rsp+A8h] [rbp-1h]

  v9 = a4;
  _HalDispatchTable = _mm_load_si128(&HalDispatchTable);
  v11 = &_HalDispatchTable;
  v12 = 0;
  v41 = -1;
  do
  {
    v11->m128i_i8[0] = ~v11->m128i_i8[0];
    ++v12;
    v11 = (__m128i *)((char *)v11 + 1);
  }
  while ( v12 < 17 );
  v13 = resolve(a1, (__int64)&_HalDispatchTable);
  if ( v13 )
  {
    v14 = (unsigned __int64 *)(v13 + 8);
    v15 = 1;
    v16 = (*(_DWORD *)v13 > 3u) + 22;
    while ( 1 )
    {
      if ( !*v14 )
        goto LABEL_57;
      v17 = (unsigned __int8)MmIsAddressValid(*v14) != 0;
      v18 = *v14;
      if ( a1 <= *v14 && v18 < a2 + a1 || a3 <= v18 && v18 < v9 + a3 )
      {
        if ( !v17 )
          goto LABEL_57;
LABEL_13:
        be::report_hook(*v14++, 28, v15++);
        if ( v15 >= v16 )
          break;
      }
      else
      {
        v30 = 27;
        v32 = v18;
        v31 = v15;
        if ( v17 )
        {
          Dst = *(__m128 *)v18;
          v34 = *(_OWORD *)(v18 + 16);
          v35 = *(_OWORD *)(v18 + 32);
          v36 = *(_OWORD *)(v18 + 48);
        }
        else
        {
          ((void (__fastcall *)(__m128 *, unsigned __int8, unsigned __int64))memset)(&Dst, 0, 0x40ui64);
        }
        be::report((__int64)&v30, 77i64);
        if ( v17 )
          goto LABEL_13;
LABEL_57:
        ++v15;
        ++v14;
        if ( v15 >= v16 )
          break;
      }
    }
  }
  v19 = (__int64)&v37;
  v37 = _mm_load_si128(&unk_1400140D0);
  v20 = 0;
  v38 = 0x9EAB979C;
  v39 = 0xFF9A939D;
  do
  {
    *(_BYTE *)v19 = ~*(_BYTE *)v19;
    ++v20;
    ++v19;
  }
  while ( v20 < 24 );
  result = (_DWORD *)resolve(a1, (__int64)&v37);
  if ( result )
  {
    v22 = *result;
    v23 = 148;
    if ( *result <= 0x2Eu )
      v23 = 139;
    if ( v22 <= 0x2B )
      v23 = 136;
    if ( v22 <= 0x28 )
      v23 = 126;
    if ( v22 <= 0x24 )
      v23 = 122;
    if ( v22 <= 0x20 )
      v23 = 119;
    if ( v22 <= 0x17 )
      v23 = 106;
    if ( v22 <= 0x15 )
      v23 = 91;
    if ( v22 <= 0xD )
      v23 = 46;
    v24 = 1;
    if ( v22 == 7 )
      v23 = 36;
    if ( v22 <= 6 )
      v23 = 34;
    v25 = (unsigned __int64 *)(result + 2);
    while ( 1 )
    {
      if ( !*v25 )
        goto LABEL_52;
      v26 = MmIsAddressValid(*v25);
      v27 = *v25;
      v28 = v26 != 0;
      if ( a1 <= *v25 && (result = (_DWORD *)(a2 + a1), v27 < (unsigned __int64)result)
        || a3 <= v27 && (result = (_DWORD *)(v9 + a3), v27 < v9 + a3)
        || a5 <= v27 && (result = (_DWORD *)(a5 + a6), v27 < (unsigned __int64)result)
        || a7 <= v27 && (result = (_DWORD *)(a7 + a8), v27 < (unsigned __int64)result) )
      {
        if ( !v28 )
          goto LABEL_52;
LABEL_50:
        result = (_DWORD *)be::report_hook(*v25++, 30, v24++);
        if ( v24 >= v23 )
          return result;
      }
      else
      {
        v30 = 29;
        v31 = v24;
        v32 = v27;
        if ( v28 )
        {
          Dst = *(__m128 *)v27;
          v34 = *(_OWORD *)(v27 + 16);
          v35 = *(_OWORD *)(v27 + 32);
          v36 = *(_OWORD *)(v27 + 48);
        }
        else
        {
          ((void (__fastcall *)(__m128 *, unsigned __int8, unsigned __int64))memset)(&Dst, 0, 0x40ui64);
        }
        result = (_DWORD *)be::report((__int64)&v30, 77i64);
        if ( v28 )
          goto LABEL_50;
LABEL_52:
        ++v24;
        ++v25;
        if ( v24 >= v23 )
          return result;
      }
    }
  }
  return result;
}