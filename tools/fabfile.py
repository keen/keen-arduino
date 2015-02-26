from fabric.context_managers import cd
from fabric.operations import run, put

def upload_ca():
    # make sure /etc/ssl/certs exists
    run('mkdir -p /etc/ssl/certs')
    # install the root ca
    put('DigiCertHighAssuranceEVRootCA.pem', '/etc/ssl/certs')
    # create the symbolic links normally created by OpenSSL's c_rehash
    with cd('/etc/ssl/certs'):
        run('ln -s DigiCertHighAssuranceEVRootCA.pem 244b5494.0')
        run('ln -s DigiCertHighAssuranceEVRootCA.pem 81b9768f.0')
