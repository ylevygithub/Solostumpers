  switch (st_mode & S_IFMT)
  {
    case S_IFREG:  return('f');    break;
    case S_IFLNK:  return('l');    break;
    case S_IFBLK:  return('b');    break;
    case S_IFCHR:  return('c');    break;
    case S_IFSOCK:  return('s');    break;
    case S_IFIFO:  return('p');    break;
    case S_IFDIR:  return('d');    break;
    default: return ('?'); break;
