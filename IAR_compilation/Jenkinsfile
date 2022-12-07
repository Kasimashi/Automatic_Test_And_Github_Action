/*
  Copyright (c) 2021-2022 IAR Systems AB.
  See LICENSE for detailed license information.
*/

pipeline {
  agent {
    /* The Docker image: change it according to your needs. */
    docker { 
      image 'iarsystems/bxarm:9.20.4' 
      args '-v LMS2:/usr/local/etc/IARSystems --hostname ${NODE_NAME}'
    }
  }
  /* The environment: change it according to your needs. */
  environment {
    BX_ARCH        = 'arm'
    BX_INSTALL_DIR = "/opt/iarsystems/bx${BX_ARCH}"
    PROJ_DIR       = "${BX_ARCH}"
    CONFIG_NAME    = 'Release'
  }
  stages {
    stage('Test compiler') {
      steps {
        echo 'If this stage fails, it is likely there is a license issue.'
        sh '${BX_INSTALL_DIR}/${BX_ARCH}/bin/icc${BX_ARCH} --version'
      }
    }
    /* Build stages */
    stage('Build: Library') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${PROJ_DIR}/library.ewp -build ${CONFIG_NAME}'
      }
    }
    stage('Build: Component A') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${PROJ_DIR}/componentA.ewp -build ${CONFIG_NAME}'
      }
    }
    stage('Build: Component B') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${PROJ_DIR}/componentB.ewp -build ${CONFIG_NAME}'
      }
    }
    /* Analysis stages */
    stage('Analyze: Library') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${PROJ_DIR}/library.ewp -cstat_analyze ${CONFIG_NAME}'
      }
    }
    stage('Analyze: Component A') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${PROJ_DIR}/componentA.ewp -cstat_analyze ${CONFIG_NAME}'
      }
    }
    stage('Analyze: Component B') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${PROJ_DIR}/componentB.ewp -cstat_analyze ${CONFIG_NAME}'
      }
    }
  }
  /* Post stages */
  post {
    always {
      echo 'This will always execute at the pipeline ending.'
      /* Load the C-STAT warnings for the recordIssues() function from the warnings-ng plugin */
      sh '${BX_INSTALL_DIR}/${BX_ARCH}/bin/icstat --db ${PROJ_DIR}/${CONFIG_NAME}/C-STAT/cstat.db load'
      recordIssues(tools: [iar(), iarCstat()])
    }
    failure {
      echo 'This will execute when one or more pipeline stages fail.'
    }
    success {
      echo 'This will execute when all pipeline stages are succesful.'
    }
  }
}
