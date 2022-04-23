unsigned __int64 be::get_CallbackListHead()
{
  unsigned __int64 v0; // rbx
  unsigned __int64 v1; // rdi
  int v2; // eax
  unsigned __int64 v3; // rcx

  CmUnRegisterCallback(0i64);
  v0 = *(_QWORD *)CmUnRegisterCallback;
  if ( *(_QWORD *)CmUnRegisterCallback )
  {
    v1 = *(_QWORD *)CmUnRegisterCallback + 4096i64;
    while ( v0 < v1 )
    {
      if ( (unsigned __int8)MmIsAddressValid(v0)
        && (unsigned __int8)MmIsAddressValid(v0 + 1)
        && (unsigned __int8)MmIsAddressValid(v0 + 2)
        && *(_BYTE *)v0 == 0x48
        && *(_BYTE *)(v0 + 1) == 0x8D
        && *(_BYTE *)(v0 + 2) == 0xD
        && *(_BYTE *)(v0 - 5) == 0x48
        && *(_BYTE *)(v0 - 4) == 0x8D
        && *(_BYTE *)(v0 - 3) == 0x54 )
      {
        v2 = *(_DWORD *)(v0 + 3);
        if ( v2 <= 0 )
          v3 = (unsigned int)v2 | 0xFFFFFFFF00000000ui64;
        else
          v3 = *(unsigned int *)(v0 + 3);
        return v0 + 7 + v3;
      }
      ++v0;
    }
  }
  return 0i64;
}