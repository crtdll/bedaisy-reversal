char __fastcall be::validate_function_integrity(char a1, struct _UNICODE_STRING *a2, __int128 *a3)
{
  __int128 *v6; // rax
  char v7; // al
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  char result; // al
  _QWORD *v12; // rbx
  unsigned int v13; // edi
  unsigned __int64 v14; // rcx
  __int128 *i; // rcx
  unsigned __int64 v16; // rdx
  char v17; // [rsp+20h] [rbp-60h] BYREF
  char v18; // [rsp+21h] [rbp-5Fh]
  char v19; // [rsp+22h] [rbp-5Eh] BYREF
  __int128 *v20; // [rsp+23h] [rbp-5Dh]
  __int128 Dst[4]; // [rsp+2Bh] [rbp-55h] BYREF

  if ( a2 )
    v6 = (__int128 *)MmGetSystemRoutineAddress(a2);
  else
    v6 = 0i64;
  if ( !a3 )
    a3 = v6;
  if ( !a2 || v6 && v6 == a3 )
  {
    if ( qword_140016830
      && ((v14 = *(_QWORD *)(qword_140016830 + 1288), (unsigned __int64)a3 < v14)
       || (unsigned __int64)a3 >= *(unsigned int *)(qword_140016830 + 1296) + v14) )
    {
      v7 = 1;                                   // eat hooked
    }
    else
    {
      for ( i = a3; ; i = *(__int128 **)((char *)i + *(unsigned int *)((char *)i + 2) + 6) )
      {
        while ( *(_BYTE *)i == 0xE9 )
          i = (__int128 *)((char *)i + *(_DWORD *)((char *)i + 1) + 5);
        if ( *(_WORD *)i != 0x25FF )
          break;
      }
      if ( i == a3
        || !qword_140016830
        || (v16 = *(_QWORD *)(qword_140016830 + 1288), (unsigned __int64)i >= v16)
        && (unsigned __int64)i < *(unsigned int *)(qword_140016830 + 1296) + v16 )
      {
        v7 = -1;                                // OK
        if ( *(_BYTE *)i == 0xCC )
          v7 = 3;                               // veh hooked
      }
      else
      {
        v7 = 2;
        a3 = i;
      }
    }
  }
  else
  {
    v7 = 0;
  }
  v19 = v7;
  v20 = a3;
  v18 = a1;
  v17 = 9;
  if ( a3 )
  {
    v8 = a3[1];
    Dst[0] = *a3;
    v9 = a3[2];
    Dst[1] = v8;
    v10 = a3[3];
    Dst[2] = v9;
    Dst[3] = v10;
  }
  else
  {
    memset(Dst, 0, sizeof(Dst));
    v7 = v19;
    a1 = v18;
  }
  if ( v7 == -1 )
  {
    v12 = (_QWORD *)qword_140016368;
    v13 = 0;
    if ( !qword_140016368 )
      goto LABEL_20;
    do
    {
      if ( *(_BYTE *)(*v12 + 1i64) == a1 )
      {
        if ( !(unsigned int)sub_140013A60((unsigned __int64 *)(*v12 + 2i64), (__int64)&v19, 0x49ui64) )
          break;
        ++v13;
      }
      v12 = (_QWORD *)v12[2];
    }
    while ( v12 );
    if ( v12 || v13 >= 3 )
    {
      result = 0;
    }
    else
    {
LABEL_20:
      be::report_custom_list((unsigned __int64)&v17, 0x4Bi64, &qword_140016368, 0x140016378i64);
      result = 0;
    }
  }
  else
  {
    be::report((__int64)&v17, 75i64);
    result = 1;
  }
  return result;
}