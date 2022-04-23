void be::check_lookup_thread_by_id()
{
  __int64 v0; // rdx
  __int64 v1; // rax
  __int64 *v2; // rax
  __int64 i; // rax
  char v4; // [rsp+30h] [rbp-68h] BYREF
  __int64 (__fastcall *v5)(_QWORD, _QWORD); // [rsp+31h] [rbp-67h]
  unsigned int v6; // [rsp+39h] [rbp-5Fh]
  __int64 v7; // [rsp+3Dh] [rbp-5Bh]
  char v8; // [rsp+45h] [rbp-53h]
  __int64 v9; // [rsp+46h] [rbp-52h] BYREF
  char v10; // [rsp+4Eh] [rbp-4Ah] BYREF

  if ( !byte_140016175 && *(_WORD *)PsLookupThreadByThreadId == 0x25FF )
  {
    KeWaitForSingleObject(0x1400161D8i64, 6i64, 0i64, 0i64, 0i64);
    v4 = 4;
    v5 = PsLookupThreadByThreadId;
    v6 = *(_DWORD *)((char *)PsLookupThreadByThreadId + 2);
    v0 = *(_QWORD *)((char *)PsLookupThreadByThreadId + v6 + 6);
    v7 = v0;
    if ( *(_WORD *)v0 == 0x25FF )
    {
      v1 = *(unsigned int *)(v0 + 2);
      v8 = 1;
      v0 = *(_QWORD *)(v1 + v0 + 6);
      v2 = (__int64 *)&v10;
      v9 = v0;
    }
    else
    {
      v8 = 0;
      v2 = &v9;
    }
    *(_OWORD *)v2 = *(_OWORD *)v0;
    for ( i = 1i64; i < 0x2E; ++i )
      *(&v4 + i) ^= 0x7Fu;
    be::report((__int64)&v4, 0x41i64);
    KeReleaseMutex(0x1400161D8i64, 0i64);
    byte_140016175 = 1;
  }
}