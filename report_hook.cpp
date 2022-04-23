unsigned __int64 __fastcall be::report_hook(unsigned __int64 a1, char a2, char a3)
{
  unsigned __int64 v3; // r9
  unsigned __int64 result; // rax
  __int128 *v6; // rcx
  __int128 v7; // xmm0
  size_t v8; // rdi
  __int64 i; // rbx
  unsigned __int64 v10; // rcx
  _BYTE *v11; // rdx
  int v12; // [rsp+30h] [rbp-D0h] BYREF
  __m128i *v13; // [rsp+38h] [rbp-C8h]
  char v14[16]; // [rsp+40h] [rbp-C0h] BYREF
  char v15[3]; // [rsp+50h] [rbp-B0h] BYREF
  unsigned __int64 v16; // [rsp+53h] [rbp-ADh]
  __int128 v17; // [rsp+5Bh] [rbp-A5h]
  __int128 *v18; // [rsp+6Bh] [rbp-95h]
  __int128 Dst[4]; // [rsp+73h] [rbp-8Dh] BYREF
  __m128i v20[16]; // [rsp+B3h] [rbp-4Dh] BYREF

  v3 = a1;
  result = a1 + 64;
  if ( a1 < a1 + 64 )
  {
    while ( *(_DWORD *)v3 != 0x25FF || *(_WORD *)(v3 + 4) )
    {
      if ( *(_WORD *)v3 == 0xB848 && *(_WORD *)(v3 + 10) == 0xE0FF )
      {
        v6 = *(__int128 **)(v3 + 2);
        goto LABEL_9;
      }
      if ( ++v3 >= result )
        return result;
    }
    v6 = *(__int128 **)(v3 + 6);
LABEL_9:
    v7 = *(_OWORD *)v3;
    v18 = v6;
    v15[0] = a2;
    v15[2] = v3 - a1;
    v17 = v7;
    v15[1] = a3;
    v16 = v3;
    if ( (unsigned __int8)MmIsAddressValid(v6) )
    {
      Dst[0] = *v18;
      Dst[1] = v18[1];
      Dst[2] = v18[2];
      Dst[3] = v18[3];
      v8 = 0i64;
      KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
    }
    else
    {
      memset(Dst, 0, sizeof(Dst));
      v8 = 0i64;
      KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
    }
    for ( i = qword_140016820; ; i = *(_QWORD *)(i + 1320) )
    {
      if ( !i )
        goto LABEL_23;
      v10 = *(_QWORD *)(i + 1288);
      if ( a1 >= v10 && a1 < *(unsigned int *)(i + 1296) + v10 )
        break;
    }
    if ( *(_WORD *)(i + 772) )
    {
      RtlInitUnicodeString(v14, i + 772);
      v12 = 0x1040000;
      v13 = v20;
      if ( (int)RtlUnicodeStringToAnsiString(&v12, v14, 0i64) >= 0 )
      {
        v8 = (unsigned __int16)v12;
        if ( (_WORD)v12 )
        {
LABEL_23:
          KeReleaseMutex(0x1400161D8i64, 0i64);
          goto LABEL_22;
        }
      }
    }
    v8 = -1i64;
    v11 = (_BYTE *)(i + 2 + *(unsigned __int16 *)i);
    do
      ++v8;
    while ( v11[v8] );
    memcpy(v20, v11, v8);
    KeReleaseMutex(0x1400161D8i64, 0i64);
LABEL_22:
    result = be::report((__int64)v15, v8 + 0x63);
  }
  return result;
}