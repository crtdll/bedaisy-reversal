__int64 be::check_objects()
{
  __int64 v0; // rcx
  __int64 *v1; // r8
  __int64 result; // rax
  __int64 v3; // rdi
  __int64 v4; // rbx
  int v5; // eax
  unsigned __int8 v6; // dl
  __int64 v7; // rcx
  int v8; // eax
  unsigned int v9; // ecx
  __int64 v10; // rbx
  __int64 v11; // rbx
  __int64 v12; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v13; // [rsp+28h] [rbp-D8h] BYREF
  char *v14; // [rsp+30h] [rbp-D0h]
  char v15[16]; // [rsp+38h] [rbp-C8h] BYREF
  char v16[16]; // [rsp+48h] [rbp-B8h] BYREF
  int v17[4]; // [rsp+58h] [rbp-A8h] BYREF
  int v18[4]; // [rsp+68h] [rbp-98h] BYREF
  int v19[6]; // [rsp+78h] [rbp-88h] BYREF
  char v20; // [rsp+90h] [rbp-70h] BYREF
  unsigned __int8 v21; // [rsp+91h] [rbp-6Fh]
  char v22[142]; // [rsp+92h] [rbp-6Eh] BYREF

  v17[0] = 0x44005C;
  v12 = 0i64;
  v17[1] = 6881394;
  v17[2] = 0x650076;
  v17[3] = 0x72;
  RtlInitUnicodeString(v15, (char *)v17 + 2);
  v0 = (__int64)sub_1403443CA((__int64)v17, (__int64)v15, (__m128i **)&v12);// \Driver
  v19[0] = 0x46005C;
  v19[1] = 0x6C0069;
  v1 = &v12;
  v19[2] = 0x530065;
  v19[3] = 0x730079;
  if ( v0 )
    v1 = (__int64 *)(v0 + 520);
  v19[4] = 0x650074;
  v19[5] = 0x6D;
  result = (__int64)sub_1403443CA((__int64)v19, (__int64)v15, (__m128i **)v1);// \FileSystem
  if ( v12 )
  {
    v18[0] = 0x44005C;
    v18[1] = 0x760065;
    v18[2] = 0x630069;
    v18[3] = 0x65;
    RtlInitUnicodeString(v15, (char *)v18 + 2);
    if ( (__int64)sub_1403443CA((__int64)v18, (__int64)v15, (__m128i **)&v13) )// \Device
    {
      v3 = v13;
      if ( v13 )
      {
        do
        {
          v4 = *(_QWORD *)(*(_QWORD *)(v3 + 0x200) + 8i64);
          if ( !(unsigned __int8)MmIsAddressValid(v4) || sub_14034E128(v12, v4) )
          {
            v10 = *(_QWORD *)(v3 + 520);
            ExFreePoolWithTag(v3, 0i64);
          }
          else
          {
            v20 = 15;
            RtlInitUnicodeString(v16, v3);
            LODWORD(v13) = 0x400000;
            v14 = v22;
            v5 = RtlUnicodeStringToAnsiString(&v13, v16, 0i64);
            v6 = 0;
            if ( v5 >= 0 )
              v6 = v13;
            v21 = v6;
            v7 = *(_QWORD *)(v4 + 64);
            v14 = &v22[v6];
            if ( !(unsigned __int8)MmIsAddressValid(v7)
              || (v8 = RtlUnicodeStringToAnsiString(&v13, v4 + 56, 0i64), v9 = (unsigned __int16)v13, v8 < 0) )
            {
              v9 = 0;
            }
            be::report((__int64)&v20, v9 + (unsigned __int64)((unsigned int)v21 + 2));
            v10 = *(_QWORD *)(v3 + 520);
            ExFreePoolWithTag(v3, 0i64);
          }
          v3 = v10;
        }
        while ( v10 );
      }
    }
    result = v12;
    if ( v12 )
    {
      do
      {
        v11 = *(_QWORD *)(result + 520);
        ExFreePoolWithTag(result, 0i64);
        v12 = v11;
        result = v11;
      }
      while ( v11 );
    }
  }
  return result;
}