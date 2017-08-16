void *Memcpy(void *dest, const void*scr, size_t count)
{
	void *ret = dest;
	assert(scr);
	assert(dest);
	char* pdest = (char*)dest;
	char* pscr = (char*)scr;
	while (count--)
	{
		*pdest = *pscr;
		pdest++,pscr++;
	}
	return ret;
}
