void **be::check_bedaisy_dispatch()
{
  void **result; // rax
  unsigned int v1; // ebx
  int v2; // eax
  __int64 v3; // rsi
  __int64 v4; // rdx
  __int64 v5; // rcx
  __int64 v6; // rdi
  __int64 v7; // rbx
  _OWORD *v8; // rcx
  int v9; // [rsp+20h] [rbp-B8h] BYREF
  char *v10; // [rsp+28h] [rbp-B0h]
  char v11; // [rsp+30h] [rbp-A8h] BYREF
  char v12[143]; // [rsp+31h] [rbp-A7h] BYREF
  void *retaddr; // [rsp+D8h] [rbp+0h] BYREF

  result = &retaddr;
  if ( !byte_1400168C0 )
  {
    v1 = 0;
    if ( *(_QWORD *)(g_driver_object + 0x70) != 0x1400020CCi64
      || (v1 = 2, *(_QWORD *)(g_driver_object + 0x80) != 0x140002028i64)
      || (v1 = 3, *(_QWORD *)(g_driver_object + 0x88) != 0x14000348Ci64)
      || (result = (void **)sub_14000551C, v1 = 4, *(_QWORD *)(g_driver_object + 144) != 0x14000551Ci64) )
    {
      v11 = 0;
      v10 = v12;
      v9 = 0x400000;
      v2 = RtlUnicodeStringToAnsiString(&v9, g_driver_object + 0x38, 0i64);
      v3 = v1;
      v4 = 0i64;
      if ( v2 >= 0 )
        v4 = (unsigned __int16)v9;
      v5 = g_driver_object;
      v6 = (unsigned int)v4;
      v12[v4] = v1;
      *(_QWORD *)&v12[v4 + 1] = *(_QWORD *)(v5 + 8i64 * v1 + 112);
      v7 = (__int64)&v12[(unsigned int)v4 + 9];
      if ( (unsigned __int8)MmIsAddressValid(*(_QWORD *)(v5 + 8 * v3 + 112)) )
      {
        v8 = *(_OWORD **)(g_driver_object + 8 * v3 + 112);
        *(_OWORD *)v7 = *v8;
        *(_OWORD *)(v7 + 16) = v8[1];
        *(_OWORD *)(v7 + 32) = v8[2];
        *(_OWORD *)(v7 + 48) = v8[3];
      }
      else
      {
        memset((void *)v7, 0, 0x40ui64);
      }
      result = (void **)be::report((__int64)&v11, v6 + 74);
      byte_1400168C0 = 1;
    }
  }
  return result;
}