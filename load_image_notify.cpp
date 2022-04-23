void **__fastcall be::load_image_notify(const wchar_t **a1, __int64 a2, __int64 a3)
{
  void **result; // rax
  __int64 v6; // rbx
  const wchar_t *v7; // rcx
  unsigned __int64 v8; // r8
  __int64 v9; // rax
  void *v10; // rax
  size_t v11; // r8
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // rcx
  void *v15; // rcx
  unsigned __int64 v16; // rdx
  __int64 v17; // rcx
  void *v18; // rax
  size_t v19; // r8
  __int64 v20; // rbx
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rcx
  __int64 v24; // rcx
  void *retaddr; // [rsp+48h] [rbp+0h] BYREF
  unsigned __int16 *v26; // [rsp+58h] [rbp+10h] BYREF

  result = &retaddr;
  if ( a2 )
  {
    if ( a2 == qword_140016138 && qword_140016210 )
    {
      KeWaitForSingleObject(&qword_1400161D8, 0i64, 0i64, 0i64, 0i64);
      v6 = qword_1400161B0;
      if ( !qword_1400161B0 )
        goto LABEL_12;
      do
      {
        v7 = (const wchar_t *)(v6 + 12);
        v8 = (unsigned __int64)*(unsigned __int16 *)a1 >> 1;
        v9 = -1i64;
        do
          ++v9;
        while ( v7[v9] );
        if ( v9 == v8 && !wcsncmp(v7, a1[1], v8) && !(unsigned __int8)sub_140002A9C(v6) )
          break;
        v6 = *(_QWORD *)(v6 + 0x220);
      }
      while ( v6 );
      if ( !v6 )
      {
LABEL_12:
        v10 = (void *)ExAllocatePoolWithTag(1i64, 552i64, 17730i64);
        v6 = (__int64)v10;
        if ( !v10 )
        {
LABEL_27:
          KeReleaseMutex(&qword_1400161D8, 0i64);
          PsGetCurrentProcessId();
          PsGetCurrentThreadId(v17);
          return (void **)KeGetCurrentIrql();
        }
        memset(v10, 0, v11);
        if ( qword_1400161B0 )
          *(_QWORD *)(qword_1400161B8 + 544) = v6;
        else
          qword_1400161B0 = v6;
        qword_1400161B8 = v6;
        v12 = *(unsigned __int16 *)a1;
        v13 = 256i64;
        if ( (unsigned __int16)v12 <= 0x200u )
        {
          v14 = 0i64;
        }
        else
        {
          v12 = (v12 >> 1) - 256;
          v14 = v12;
        }
        ((void (__fastcall *)(__m128i *, unsigned __int64, unsigned __int64))memcpy)(
          (__m128i *)(v6 + 12),
          (unsigned __int64)&a1[1][v14],
          v12);
        if ( *(_WORD *)a1 <= 0x200u )
          v13 = (unsigned __int64)*(unsigned __int16 *)a1 >> 1;
        *(_WORD *)(v6 + 2 * v13 + 12) = 0;
      }
      *(_QWORD *)v6 = *(_QWORD *)(a3 + 8);
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(a3 + 24);
      if ( !*(_DWORD *)(v6 + 536) && v6 == qword_1400161B0 )
      {
        *(_DWORD *)(v6 + 536) = 1;
        v15 = *(void **)(a3 + 40);
        *(_QWORD *)(v6 + 528) = v15;
        ObfReferenceObject(v15);
      }
      if ( byte_140016174 )
      {
        v16 = *(_QWORD *)(a3 + 8);
        if ( qword_140016218 >= v16 && qword_140016218 < *(_QWORD *)(a3 + 24) + v16 )
        {
          byte_140016174 = 0;
          qword_140016218 = 0i64;
        }
      }
      goto LABEL_27;
    }
  }
  else
  {
    if ( (int)IoQueryFileDosDeviceName(*(_QWORD *)(a3 + 40), &v26) >= 0 )
    {
      v18 = (void *)ExAllocatePoolWithTag(1i64, 1328i64, 17730i64);
      v20 = (__int64)v18;
      if ( v18 )
      {
        memset(v18, 0, v19);
        v21 = 256i64;
        v22 = *v26;
        if ( (unsigned __int16)v22 <= 0x200u )
        {
          v23 = 0i64;
        }
        else
        {
          v22 = (v22 >> 1) - 256;
          v23 = v22;
        }
        ((void (__fastcall *)(__m128i *, unsigned __int64, unsigned __int64))memcpy)(
          (__m128i *)(v20 + 258),
          *((_QWORD *)v26 + 1) + 2 * v23,
          v22);
        if ( *v26 <= 0x200u )
          v21 = (unsigned __int64)*v26 >> 1;
        *(_WORD *)(v20 + 2 * v21 + 258) = 0;
        *(_DWORD *)(v20 + 1296) = *(_DWORD *)(a3 + 24);
        v24 = *(_QWORD *)(a3 + 8);
        *(_QWORD *)(v20 + 1288) = v24;
        if ( (unsigned __int8)MmIsAddressValid(v24) )
        {
          *(_DWORD *)(v20 + 1300) = *(_DWORD *)(*(int *)(*(_QWORD *)(a3 + 8) + 0x3Ci64) + *(_QWORD *)(a3 + 8) + 40i64);
          *(_DWORD *)(v20 + 1304) = *(_DWORD *)(*(int *)(*(_QWORD *)(a3 + 8) + 0x3Ci64) + *(_QWORD *)(a3 + 8) + 8i64);
          *(_DWORD *)(v20 + 1308) = *(_DWORD *)(*(int *)(*(_QWORD *)(a3 + 8) + 0x3Ci64) + *(_QWORD *)(a3 + 8) + 172i64);
        }
        KeWaitForSingleObject(&qword_1400161D8, 0i64, 0i64, 0i64, 0i64);
        if ( qword_140016820 )
          *(_QWORD *)(qword_1400161C0 + 1320) = v20;
        else
          qword_140016820 = v20;
        qword_1400161C0 = v20;
        if ( qword_140016828 )
          *(_QWORD *)(qword_1400161C8 + 1320) = v20;
        else
          qword_140016828 = v20;
        qword_1400161C8 = v20;
        KeReleaseMutex(&qword_1400161D8, 0i64);
      }
      ExFreePoolWithTag(v26, 0i64);
    }
    result = (void **)sub_140100619((__int64)a1, a3);
  }
  return result;
}