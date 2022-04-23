void __fastcall be::create_thread_notify(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // rcx
  __int64 v5; // rcx
  int v6; // [rsp+28h] [rbp-50h]
  __int64 v7; // [rsp+40h] [rbp-38h] BYREF
  __int64 v8; // [rsp+48h] [rbp-30h] BYREF
  unsigned __int64 v9; // [rsp+50h] [rbp-28h] BYREF
  char v10; // [rsp+58h] [rbp-20h] BYREF
  __int64 v11; // [rsp+59h] [rbp-1Fh]

  if ( a1 == qword_140016138 && qword_140016210 && a3 )
  {
    if ( PsGetThreadProcessId(KeGetCurrentThread()) != qword_140016138 )
    {
      if ( qword_140016218 && byte_140016174 )
        byte_140016174 = 0;
      if ( (int)PsLookupThreadByThreadId(a2, &v8) >= 0 )
      {
        LOBYTE(v6) = 0;
        if ( (int)ObOpenObjectByPointer(v8, 512i64, 0i64, 0i64, *PsThreadType, v6, &v7) >= 0 )
        {
          if ( (int)ZwQueryInformationThread(v7, 9i64, &v9) >= 0 )
          {
            KeWaitForSingleObject(&qword_1400161D8, 0i64, 0i64, 0i64, 0i64);
            v5 = qword_1400161B0;
            if ( !qword_1400161B0 )
              goto LABEL_17;
            do
            {
              if ( *(_QWORD *)v5 <= v9 && *(_QWORD *)v5 + (unsigned __int64)*(unsigned int *)(v5 + 8) > v9 )
                break;
              v5 = *(_QWORD *)(v5 + 0x220);
            }
            while ( v5 );
            if ( !v5 )
            {
LABEL_17:
              if ( byte_140016174 || !qword_140016218 )
                qword_140016218 = v9;
            }
            KeReleaseMutex(&qword_1400161D8, 0i64);
          }
          ZwClose(v7);
        }
        ObfDereferenceObject(v8);
      }
      if ( qword_140016218 )
      {
        if ( !byte_140016174 )
        {
          v10 = 3;
          v11 = qword_140016218;
          j_j_be::report_internal_2(&v10, 9);
        }
      }
    }
    j_j_be::check_lookup_thread_by_id(v4);
  }
}