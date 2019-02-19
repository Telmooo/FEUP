alarm = lambda hour, minutes: f"{str((hour+6)%24 + (minutes+51)//60).zfill(2)}:{str((minutes+51)%60).zfill(2)}"
