char *__fastcall be::get_pe_section(char *a1, __int64 a2, _DWORD *AddressOfEntryPoint)
{
  PIMAGE_NT_HEADERS v6; // rax
  PIMAGE_NT_HEADERS v7; // rdi
  __int64 v8; // rbx
  USHORT v9; // si

  v6 = RtlImageNtHeader(a1);
  v7 = v6;
  if ( !v6 )
    return 0i64;
  v8 = (__int64)&v6->OptionalHeader + v6->FileHeader.SizeOfOptionalHeader;
  v9 = 0;
  if ( !v6->FileHeader.NumberOfSections )
    return 0i64;
  while ( (unsigned int)qword_140016268(v8, a2, 8i64) )
  {
    ++v9;
    v8 += 40i64;
    if ( v9 >= v7->FileHeader.NumberOfSections )
      return 0i64;
  }
  if ( AddressOfEntryPoint )
    *AddressOfEntryPoint = *(_DWORD *)(v8 + 16);
  return &a1[*(unsigned int *)(v8 + 12)];
}