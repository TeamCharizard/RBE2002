from lidar import Lidar
import requests
import json



if __name__ == "__main__":
    lidar = Lidar()

    revs = 0

    while True:
        completeRevolution = lidar.read()
        if (completeRevolution):
          revs+=1;

        #try sending every 4 spins?
        if (revs == 4):
          revs = 0
          distances = lidar.getLatestDistances()
          angles = range(360)
          combined = zip(angles, distances)
          # send data to server!
          json_encoded = json.dumps({"data":combined})
          data = {"data": json_encoded}
          req = requests.post('http://charizard.elasticbeanstalk.com/publish/',data=data)

          print req.text
