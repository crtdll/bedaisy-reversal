__int64 __fastcall be::resolve(__int64 a1, __int64 a2)
{
  __int64 v2; // r9
  __int64 v4; // r8
  __int64 v5; // rdx

  v2 = 0i64;
  if ( a1 )
  {
    v4 = *(unsigned int *)(a1 + 0x3C) + a1 + 24;
    if ( v4 )
    {
      v5 = a1 + *(unsigned int *)(v4 + 112);
      if ( v5 )
        v2 = sub_14034BE74((unsigned int)a1, (_DWORD *)(_DWORD)v5, *(_DWORD *)(v4 + 116), 1, (char *)a2, 0);
    }
  }
  return v2;
}

unsigned __int64 __fastcall sub_14034BE74(__int64 a1, _DWORD *a2, unsigned int a3, int a4, char *a5, unsigned int a6)
{
  int v6; // ebx
  __int64 v8; // rbp
  __int64 v11; // rsi
  __int64 v12; // r9
  unsigned __int64 result; // rax
  int v14; // eax
  int v15; // edx
  int v16; // eax
  char *v17; // rcx
  __int64 v18; // rdi
  char v19; // r8
  int v20; // ecx

  v8 = a3;
  if ( !a2 || !a3 )
    return 0i64;
  v11 = (unsigned int)a2[8] + a1;
  v12 = (unsigned int)a2[9] + a1;
  if ( !a4 )
    return *(unsigned int *)(a1 + (unsigned int)a2[7] + 4i64 * a6);
  v14 = a2[6];
  v15 = 0;
  v16 = v14 - 1;
  if ( v16 < 0 )
    return 0i64;
  while ( 1 )
  {
    v17 = a5;
    v18 = *(unsigned int *)(v11 + 4i64 * v6) + a1 - (_QWORD)a5;
    while ( 1 )
    {
      v19 = *v17;
      if ( v17[v18] != *v17 )
        break;
      ++v17;
      if ( !v19 )
      {
        v20 = 0;
        goto LABEL_11;
      }
    }
    v20 = (unsigned __int8)v17[v18] < (unsigned __int8)*v17 ? -1 : 1;
LABEL_11:
    if ( v20 >= 0 )
      break;
    v16 = v6 - 1;
LABEL_13:
    if ( v16 < v15 )
      goto LABEL_14;
  }
  if ( v20 > 0 )
  {
    v15 = v6 + 1;
    goto LABEL_13;
  }
LABEL_14:
  if ( v16 < v15 )
    return 0i64;
  _mm_lfence();
  if ( (unsigned int)*(unsigned __int16 *)(v12 + 2i64 * v6) >= a2[5] )
    return 0i64;
  _mm_lfence();
  result = *(unsigned int *)((unsigned int)a2[7] + a1 + 4i64 * *(unsigned __int16 *)(v12 + 2i64 * v6)) + a1;
  if ( result > (unsigned __int64)a2 && result < (unsigned __int64)a2 + v8 )
    result = 0i64;
  return result;
}