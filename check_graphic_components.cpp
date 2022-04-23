_DWORD *__fastcall be::check_graphic_components(unsigned __int64 a1, unsigned int a2)
{
  __m128i *v2; // r8
  __int64 v3; // r15
  unsigned int i; // er9
  _DWORD *result; // rax
  unsigned int v7; // edi
  unsigned int v8; // esi
  __int128 **v9; // rbx
  __int128 *v10; // rcx
  __int128 *v11; // rax
  __int128 *v12; // rcx
  char v13; // [rsp+20h] [rbp-29h] BYREF
  unsigned int v14; // [rsp+21h] [rbp-28h]
  __int128 *v15; // [rsp+25h] [rbp-24h]
  __int128 Dst[4]; // [rsp+2Dh] [rbp-1Ch] BYREF
  __m128i _DxgCoreInterface; // [rsp+70h] [rbp+27h] BYREF
  char v18; // [rsp+80h] [rbp+37h]

  v2 = &_DxgCoreInterface;
  _DxgCoreInterface = _mm_load_si128(&DxgCoreInterface);
  v3 = a2;
  v18 = -1;
  for ( i = 0; i < 17; ++i )
  {
    v2->m128i_i8[0] = ~v2->m128i_i8[0];
    v2 = (__m128i *)((char *)v2 + 1);
  }
  result = (_DWORD *)resolve(a1, (__int64)&_DxgCoreInterface);
  if ( result )
  {
    v7 = 1;
    v8 = *result >> 3;
    if ( v8 > 1 )
    {
      v9 = (__int128 **)(result + 2);
      while ( 1 )
      {
        v10 = *v9;
        if ( a1 <= (unsigned __int64)*v9 && (result = (_DWORD *)(v3 + a1), (unsigned __int64)v10 < v3 + a1) )
        {
          v12 = *v9;
          if ( !*v9 )
            goto LABEL_13;
LABEL_11:
          result = (_DWORD *)be::report_hook((unsigned __int64)v12, 13, v7++);
          ++v9;
          if ( v7 >= v8 )
            return result;
        }
        else
        {
          v13 = 12;
          v15 = v10;
          v14 = v7;
          if ( (unsigned __int8)MmIsAddressValid(v10) )
          {
            v11 = *v9;
            Dst[0] = **v9;
            Dst[1] = v11[1];
            Dst[2] = v11[2];
            Dst[3] = v11[3];
          }
          else
          {
            memset(Dst, 0, sizeof(Dst));
          }
          result = (_DWORD *)be::report((__int64)&v13, 77i64);
          v12 = *v9;
          if ( *v9 )
            goto LABEL_11;
LABEL_13:
          ++v7;
          ++v9;
          if ( v7 >= v8 )
            return result;
        }
      }
    }
  }
  return result;
}