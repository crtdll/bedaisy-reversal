unsigned __int64 __fastcall be::report_manual_mapped_driver(unsigned __int64 a1, char a2)
{
  unsigned __int64 v4; // rcx
  unsigned __int64 result; // rax
  __int64 i; // rdi
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  unsigned __int64 v10; // rdx
  char v11[2]; // [rsp+30h] [rbp-68h] BYREF
  unsigned __int64 v12; // [rsp+32h] [rbp-66h]
  __m128 v13[4]; // [rsp+3Ah] [rbp-5Eh] BYREF

  v4 = *(_QWORD *)(g_driver_object + 24);
  if ( a1 < v4 || (result = *(unsigned int *)(g_driver_object + 32) + v4, a1 >= result) )
  {
    KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
    for ( i = qword_140016820; i; i = *(_QWORD *)(i + 0x528) )
    {
      v10 = *(_QWORD *)(i + 0x508);
      if ( a1 >= v10 && a1 < *(unsigned int *)(i + 0x510) + v10 )
        break;
    }
    result = KeReleaseMutex(0x1400161D8i64, 0i64);
    if ( !i )
    {
      v11[0] = 7;
      v11[1] = a2;
      v12 = a1;
      if ( (unsigned __int8)MmIsAddressValid(a1) )
      {
        v7 = *(__m128 *)(a1 + 16);
        v13[0] = *(__m128 *)a1;
        v8 = *(__m128 *)(a1 + 32);
        v13[1] = v7;
        v9 = *(__m128 *)(a1 + 48);
        v13[2] = v8;
        v13[3] = v9;
      }
      else
      {
        ((void (__fastcall *)(__m128 *, unsigned __int8, unsigned __int64))memset)(v13, 0, 0x40ui64);
      }
      result = be::report((__int64)v11, 0x4Ai64);
    }
  }
  return result;
}