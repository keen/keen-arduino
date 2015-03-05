from fabric.context_managers import cd
from fabric.operations import env, local, put, run

def upload_ca():
    # use sh instead of bash
    env.shell = '/bin/sh -c'
    # make sure /etc/ssl/certs exists
    run('mkdir -p /etc/ssl/certs')
    # install the root ca
    # cannot use 'put' as sftp is not available
    #put('DigiCertHighAssuranceEVRootCA.pem', '/etc/ssl/certs')
    for host in env.hosts:
        local('scp DigiCertHighAssuranceEVRootCA.pem root@{0}:/etc/ssl/certs/'.format(host))
    # create the symbolic links normally created by OpenSSL's c_rehash
    with cd('/etc/ssl/certs'):
        run('ln -s DigiCertHighAssuranceEVRootCA.pem 244b5494.0')
        run('ln -s DigiCertHighAssuranceEVRootCA.pem 81b9768f.0')
