__int64 __fastcall be::report_custom_list(unsigned __int64 a1, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 result; // rax
  __int64 v9; // rbx
  void *v10; // rax

  result = ExAllocatePool(1i64, 24i64);
  v9 = result;
  if ( result )
  {
    v10 = (void *)ExAllocatePool(1i64, a2);
    *(_QWORD *)v9 = v10;
    if ( v10 )
    {
      *(_DWORD *)(v9 + 8) = a2;
      memcpy(v10, (const void *)a1, (unsigned int)a2);
      *(_QWORD *)(v9 + 16) = 0i64;
      *(_BYTE *)(v9 + 12) = 0;
      KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
      if ( *a3 )
        *(_QWORD *)(*(_QWORD *)a4 + 16i64) = v9;
      else
        *a3 = v9;
      *(_QWORD *)a4 = v9;
      result = KeReleaseMutex(0x1400161D8i64, 0i64);
    }
    else
    {
      result = ExFreePoolWithTag(v9, 0i64);
    }
  }
  return result;
}