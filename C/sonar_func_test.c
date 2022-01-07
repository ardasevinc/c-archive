int sonar(int x, int y, int shipsize, int orientation)
{
  int x_org = x, y_org = y, n = (shipsize+2), x_count=0, y_count=0;

  if (shipsize > 1 && orientation == 1){
    while (elements[x-1][y-1] == '.'){
      if (y_count == n*3) return 1;
      if (y_count % 3 == 0) x++ y -= 2;
      y++ y_count++;
    }
    return 0;
  }
  else if (shipsize > 1 && orientation == 0){
    while (elements[x+1][y-1] == '.'){
      if (x_count == n*3) return 1;
      if (x_count % 3 == 0) y++ x -= 2;
      x-- x_count++;
    }
  }
}
