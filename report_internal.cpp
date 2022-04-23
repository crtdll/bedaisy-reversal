__int64 __fastcall be::report_internal(_BYTE *a1, int a2)
{
  __int64 result; // rax
  __int64 v5; // rbx
  __int64 v6; // rax
  int v7; // eax
  char v8; // r8
  __int64 v9; // rcx
  int v10; // edx
  _BYTE *v11; // rdi
  char v12; // al
  __int64 seed; // [rsp+50h] [rbp+18h] BYREF

  result = ExAllocatePoolWithTag(1i64, 24i64, 'EB');
  v5 = result;
  if ( result )
  {
    *(_DWORD *)(result + 8) = a2 + 4;
    v6 = ExAllocatePoolWithTag(1i64, (unsigned int)(a2 + 4), 'EB');
    *(_QWORD *)v5 = v6;
    if ( v6 )
    {
      seed = MEMORY[0xFFFFF78000000320];
      v7 = RtlRandomEx(&seed);
      v8 = v7;
      **(_DWORD **)v5 = v7;
      v9 = *(_QWORD *)v5 + 4i64;
      if ( *(_QWORD *)v5 == -4i64 )
        v9 = (__int64)a1;
      v10 = 0;
      if ( a2 > 0 )
      {
        v11 = &a1[-v9];
        do
        {
          v12 = v10++ ^ v8 ^ v11[v9];
          v12 ^= 0xA5u;                         // poggers driver -> client encryption
          *(_BYTE *)v9++ = v12;
          v8 = ~v12;
        }
        while ( v10 < a2 );
      }
      *(_QWORD *)(v5 + 16) = 0i64;
      KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
      if ( g_report_head )
        *(_QWORD *)(g_report_linked_list + 16) = v5;
      else
        g_report_head = v5;
      g_report_linked_list = v5;
      result = KeReleaseMutex(0x1400161D8i64, 0i64);
    }
    else
    {
      result = ExFreePoolWithTag(v5, 0i64);
    }
  }
  return result;
}