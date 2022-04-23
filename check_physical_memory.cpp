__int64 __fastcall be::check_physical_memory(__int64 physical_memory)
{
  __int64 result; // rax
  __int64 v2; // rcx
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int128 v5; // xmm0
  __int128 v6; // xmm1
  __int64 v7; // [rsp+20h] [rbp-40h] BYREF
  __int64 v8; // [rsp+28h] [rbp-38h] BYREF
  char v9; // [rsp+30h] [rbp-30h] BYREF
  __int128 v10; // [rsp+31h] [rbp-2Fh]
  __int128 v11; // [rsp+41h] [rbp-1Fh]

  v8 = 0i64;
  v7 = 0i64;
  result = sub_1403453AF(&v8, (__int64)&v7, physical_memory);
  if ( (int)result >= 0 )
  {
    if ( *(_WORD *)NtBuildNumber_0 > 0x2580u )
    {
      v3 = v7;
      v4 = *(_QWORD *)(v7 + 0x28);
    }
    else
    {
      v2 = 0i64;
      v3 = v7;
      if ( *(_WORD *)NtBuildNumber_0 == 0x23F0 )
        v2 = 8i64;
      v4 = **(_QWORD **)(v7 - v2 + 0x28);
    }
    if ( *(_QWORD *)(v4 + 48) )
    {
      v5 = *(_OWORD *)(v4 + 0x18);
      v9 = 8;
      v6 = *(_OWORD *)(v4 + 0x28);
      v10 = v5;
      v11 = v6;
      be::report((__int64)&v9, 0x21i64);
      v3 = v7;
    }
    ObfDereferenceObject(v3);
    result = ZwClose(v8);
  }
  return result;
}