# Tools

## Upload Certificate Authority

In order to make HTTP requests, the Arduino Yun sends serial data over the Bridge and the AR9331 makes curl requests. However, the Linux distribution that ships with the Arduino Yun does not include any certificate authorities - the included [HttpClient](https://github.com/arduino/Arduino/blob/master/libraries/Bridge/src/HttpClient.cpp) simply passes curl the `--insecure` flag. This means that while your connection to [https://api.keen.io](https://api.keen.io) is encrypted, the identity of the host is not being verified with a trusted certificate authority. This leaves you vulnerable to a [Man-in-the-middle attack(MITM)](https://en.wikipedia.org/wiki/Man-in-the-middle_attack).

This directory contains a tool for uploading [https://api.keen.io](https://api.keen.io)'s root certificate authority to the Arduino Yun to enable host validation.

### Requirements

The upload tools is a python script that depends on [Fabric](https://github.com/fabric/fabric) and [scp.py](https://github.com/jbardin/scp.py). The requirements are located in `requirements.txt` and can be installed via pip.

```sh
cat requirements.txt

Fabric==1.10.1
scp==0.9.0
```

```py
pip install -r requirements.txt
```

### Usage

The upload tool uses fabric to run tasks on the Arduino Yun. To upload the certificate authority, specify a HOST\_IP\_ADDR, USERNAME, and PASSWORD.

```sh
fab -H HOST_IP_ADDR -u USERNAME -p PASSWORD upload_ca
```

The default username for the Arduino Yun is `root` and the default password is `arduino`. For more Fabric help and command line arguments, visit [http://docs.fabfile.org/en/latest/usage/fab.html](http://docs.fabfile.org/en/latest/usage/fab.html).
