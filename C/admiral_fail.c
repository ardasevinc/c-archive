int sonar(int x, int y, int size)
{
  int i, x_org=x, y_org=y;

  if (x == 9 && y == 0){
    if (rand_val == 0)
      return 0;
    if (elements[x][y] != '.')
      return 0;
    else{
        for (i=0; i<size+1; i++){
          if (elements[x][y] != '.')
            return 0;
          else
            x--;
        }
        x = x_org;

        for (i=0; i<size+1; i++){
          if (elements[x][y] != '.')
            return 0;
          else
            y++;
        }
        y = y_org;
        if (elements[x-1][y+1] != '.')
          return 0;
        return 1;
        }
  }
  if (x == 0 && y == 0){
    if (elements[x][y] != '.')
      return 0;
    else{
        for (i=0; i<size+1; i++){
          if (elements[x][y] != '.')
            return 0;
          else
            x++;
        }
        x = x_org;

        for (i=0; i<size+1; i++){
          if (elements[x][y] != '.')
            return 0;
          else
            y++;
        }
        y = y_org;
        if (elements[x+1][y+1] != '.')
          return 0;
        return 1;
        }
  }
  if (y == 9 && x == 0){
    if (rand_val != 0)
      return 0;
    if (elements[x][y] != '.')
      return 0;
    else{
        for (i=0; i<size+1; i++){
          if (elements[x][y] != '.')
            return 0;
          else
            x++;
        }
        x = x_org;

        for (i=0; i<size+1; i++){
          if (elements[x][y] != '.')
            return 0;
          else
            y--;
        }
        y = y_org;
        if (elements[x+1][y-1] != '.')
          return 0;
        return 1;
        }
  }
  if (y == 9 && x == 9)
    return 0;

  if ((y > 0 && y < 9) && x == 0){
    if (elements[x][y-1] != '.')
      return 0;
    else{
      for (i=0; i<size+1; i++){
        if (elements[x][y] != '.')
          return 0;
        else
          x++;
      }
      x = x_org;
      for (i=0; i<size+1; i++){
        if (elements[x][y+1] != '.')
          return 0;
        else
          x++;
      }
      x = x_org;
      return 1;
    }
  }
  if ((y > 0 && y < 9) && x == 9){
    if (elements[x][y-1] != '.')
      return 0;
    if (elements[x-1][y-1] != '.')
      return 0;

    for (i=0; i<size+1; i++){
      if (elements[x][y] != '.')
        return 0;
      else
        y++;
    }
    y = y_org;
    for (i=0; i<size+1; i++){
      if (elements[x+1][y] != '.')
        return 0;
      else
        y++;
    }
    y = y_org;
    return 1;
  }
  if ((x > 0 && x < 9) && y == 9){
    if (elements[x][y] != '.')
      return 0;
    if (elements[x-1][y] != '.')
      return 0;
    if (elements[x-1][y-1] != '.')
      return 0;

    for (i=0; i<size+1; i++){
      if (elements[x][y] != '.')
        return 0;
      else
        x++;
    }
    x = x_org;
    for (i=0; i<size+1; i++){
      if (elements[x][y-1] != '.')
        return 0;
      else
        x++;
    }
    x = x_org;
    return 1;
  }
  if ((x > 0 && x < 9) && y == 0){
    if (elements[x][y] != '.')
      return 0;
    if (elements[x-1][y] != '.')
      return 0;
    if (elements[x-1][y+1] != '.')
      return 0;

    for (i=0; i<size+1; i++){
      if (elements[x][y] != '.')
        return 0;
      else
        x++;
    }
    x = x_org;

    for (i=0; i<size+1; i++){
      if (elements[x][y+1] != '.')
        return 0;
      else
        x++;
    }
    x = x_org;
    return 1;
  }
  if (elements[x][y] != '.')
    return 0;

  for (i=0; i<size+1; i++){
    if (elements[x][y] != '.')
      return 0;
    else
      x++;
  }
  x = x_org;

  for (i=0; i<size+1; i++){
    if (elements[x][y+1] != '.')
      return 0;
    else
      x++;
  }
  x = x_org;

  for (i=0; i<size+1; i++){
    if (elements[x][y-1] != '.')
      return 0;
    else
      x++;
  }
  x = x_org;

  for (i=0; i<3; i++){
    if (elements[x-1][y-1] != '.')
      return 0;
    else
      y++;
  }
  y = y_org;

  return 1;
}
