from fabric.context_managers import cd
from fabric.operations import env, local, put, run
from paramiko import SSHClient
from scp import SCPClient

def upload_ca():
    # use sh instead of bash
    env.shell = '/bin/sh -c'
    # make sure /etc/ssl/certs exists
    run('mkdir -p /etc/ssl/certs')
    # install the root ca
    # cannot use 'put' as sftp is not available
    ssh = SSHClient()
    ssh.load_system_host_keys()
    for host in env.hosts:
        if env.key_filename is None:
            ssh.connect(host, username=env.user, password=env.password)
        else:
             ssh.connect(host)
        scp = SCPClient(ssh.get_transport())
        scp.put('DigiCertHighAssuranceEVRootCA.pem', '/etc/ssl/certs') 
    # create the symbolic links normally created by OpenSSL's c_rehash
    with cd('/etc/ssl/certs'):
        run('ln -s DigiCertHighAssuranceEVRootCA.pem 244b5494.0')
        run('ln -s DigiCertHighAssuranceEVRootCA.pem 81b9768f.0')
