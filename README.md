<p align="center">
  <a href="https://github.com/danopstech/starlink">
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/logo.png" alt="Logo" width="130" height="130">
  </a>

<h3 align="center">Starlink Monitoring System</h3>

<p align="center">
🛰️ Measuring the performance of your "Beta" Starlink internet connection! 📡
<br />
Not affiliated with or acting on behalf of Starlink™️
<br />
<br />
<a href="https://github.com/danopstech/starlink/issues/new?assignees=dwillcocks&labels=bug&template=bug_report.md&title=">Report Bug</a>
•
<a href="https://github.com/danopstech/starlink/issues/new?assignees=dwillcocks&labels=enhancement&template=feature_request.md&title=">Request Feature</a>
</p>

<p align="center">
    <a href="https://github.com/danopstech/starlink/blob/main/LICENSE">
        <img alt="Build Status" src="https://img.shields.io/github/license/danopstech/starlink">
    </a>
    <a href="https://github.com/danopstech/starlink/issues">
        <img alt="Build Status" src="https://img.shields.io/github/issues/danopstech/starlink">
    </a>
    <a href="https://docs.docker.com/compose/compose-file/compose-versioning/">
        <img alt="Build Status" src="https://img.shields.io/badge/docker--compose-v3.3-blue">
    </a>
    <a href="https://github.com/prometheus/prometheus/releases">
        <img alt="Build Status" src="https://img.shields.io/badge/prometheus-v2.28.0-%23e6522c">
    </a>
    <a href="https://github.com/grafana/grafana/releases">
        <img alt="Build Status" src="https://img.shields.io/badge/grafana-v8.0.3-%23e6522c">
    </a>
    <a href="https://github.com/prometheus/blackbox_exporter/releases">
        <img alt="Build Status" src="https://img.shields.io/badge/blackbox_exporter-v0.19.0-%23e6522c">
    </a>
    <a href="https://github.com/danopstech/starlink_exporter/releases">
        <img alt="Build Status" src="https://img.shields.io/github/v/release/danopstech/starlink_exporter?color=orange&label=starlink%20exporter">
    </a>
    <a href="https://github.com/danopstech/speedtest_exporter/releases">
        <img alt="Build Status" src="https://img.shields.io/github/v/release/danopstech/speedtest_exporter?color=orange&label=speedtest%20exporter">
    </a>
</p>

<p align="center">
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/screenshot1.jpg" width="32%"/> 
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/screenshot2.jpg" width="32%"/>
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/screenshot3.jpg" width="32%"/>
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/screenshot4.jpg" width="32%"/>
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/screenshot5.jpg" width="32%"/>
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/screenshot6.jpg" width="32%"/>
</p>

## 🏗️ Built With

- 🐳 **[Starlink exporter](https://github.com/danopstech/starlink_exporter)** - talks to the Starlink dish via gRPC and exposes metrics in a format Prometheus understands.
- 🐳 **[Speedtest exporter](https://github.com/danopstech/speedtest_exporter)** - When asked it carries out a ping,upload and download test to [speedtest.net](https://www.speedtest.net/).
- 🐳 **[Blackbox exporter](https://github.com/prometheus/blackbox_exporter/)** - Carries out high frequency ping tests.
- 🐳 **[Grafana](https://grafana.com/)** - used to compose observability dashboards.
- 🐳 **[Prometheus](https://prometheus.io/)** - implements a highly dimensional data model.
- 🐳 **[Docker-Compose](https://docs.docker.com/compose/)** -  for defining and running multi-container Docker applications.

## 👋 Overview

I hope this project will make it easier for users to monitor their Starlink connection in even more detail, see its performance over time with each beta software release, but most importantly brag about their new satellite base internet to EVERYONE!

**What does this do?**
1. Collects information from the Starlink dish every 3 seconds such as: signal strength, alarms, obstructions and latency
2. Runs internet speed tests every 60 minutes (upload, download, ping)
3. Measures latency to multiple destinations globally every 3 seconds
4. Stores all the metrics in a local database (Prometheus time series database)
5. You can then view the metrics on pre-built dashboards or create your own dashboards in Grafana.

<p align="center">
    <img src="https://github.com/danopstech/starlink/raw/main/.docs/assets/overview.png" width="95%"/> 
</p>

⚠️ IMPORTANT: When running; this will carry out speedtests every 60 minutes, which will download and upload a fair amount of data over time. Please bare this in mind if your internet connection fails over to tethered/mobile or a data chargeable supplier when Starlink is not available.

## 🏎️ Quick Start

If you have good knowledge of the above technologies, possibly a Developer, DevOps Engineer, etc then quick start is for you:

1. Clone the repo and `cd` into your local copy
2. `docker-compose pull && docker-compose up --remove-orphan`
3. Grafana is on `localhost:3000` (admin/admin)
4. The others services are on the ports as per the above diagram.

## 🐢 Detailed Start (Slower Start)

### Pre-requisites
Ensure you install the latest version of docker and docker-compose on your host machine.

- [Docker](https://docs.docker.com/get-docker/)
- [Docker Compose](https://docs.docker.com/compose/install/)

To test you have both installed correctly, open your `Shell or Terminal` and run following commands:
```bash
$ docker --version
```
```bash
$ docker-compose --version
```

### Install

After installing the pre-requisites, You need all the files within this Github Repository downloaded to the machine you want to run the monitoring from.
This machine must be connected to the same network as the Starlink dish (more then likely the Starlink wifi).

- If you know `git` and have it installed then clone the repository - https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository

- Or use Github desktop - https://desktop.github.com/

- Or if you don't know `git` and/or don't want to install it then you can download the files as a [zip here](https://github.com/danopstech/starlink/archive/refs/heads/main.zip) or from clicking the green code button (top right)

> 💡 Please **Star** and **Watch** the repository to hopefully get updates as new features are added

Quick overview of the file structure you now have locally (for information only, you don't really need to know this):
```bash
starlink
├── .docs                      # Extra docs and images
├── config                     # Configuration for each service
│   ├── grafana            
│   │   └── provisioning       
│   │        ├── dashboards    # The preloaded dashboards
│   │        └── datasources   # The preloaded config to talk with prometheus
│   ├── prometheus             # Prometheus config file
│   └── blackbox               # Blackbox exporter config file
├── data                       # Persistent data
│    ├── grafana               # Grafana will store its running files here
│    └── prometheus            # Prometheus will store its running files here
└── docker-compose.yaml        # Defines all the applications to run
```

### Setup

Open a terminal again and `cd` into the directory of your local copy. we will start all the services using Docker Compose and see logs on the terminal. The logs should quieten down, then your ready to read the "usage" section.

```bash
$ cd <path-to-your-copy>
$ docker-compose pull && docker-compose up --remove-orphan
```

### Upgrading

The Docker Compose file will run the latest versions of all the applications. To upgrade you need to pull the new image versions and then restart the current running ones. 

As we ran the original `docker-compose up` in the foreground, so we could watch the logs. Your need to open a new terminal and `cd` to the repository directory.

```bash
$ docker-compose pull
$ docker-compose restart
```

### Stopping

To stop you can `ctrl-c` the foreground task in the original terminal and then:
```bash
$ docker-compose down
```

## 📈 Usage (from the browser)

**Grafana:** 
- This is where the pretty graphs are
- Access via your browser at [http://localhost:3000](http://localhost:3000)
- The username and password is "admin" (no need to change it, its only local)
- Pre-loaded dashboards are Starlink, Speedtest, Ping

**Prometheus**
- If you know [promQL](https://prometheus.io/docs/prometheus/latest/querying/basics/), this is where you can create adhoc queries
- Access via your browser at [http://localhost:9090](http://localhost:9090)
- You can check the state of the exporters [here](http://localhost:9090/targets)

**Starlink Exporter**
- Standard usage there is no need to visit this
- Access via your browser at [http://localhost:9817](http://localhost:9817)
- `/metrics` link will get the latest metrics from the Starlink dish
- `/health` link shows you the gRPC connection state to the dish

**Speedtest Exporter**
- Standard usage there is no need to visit this
- Access via your browser at [http://localhost:9092](http://localhost:9092)
- `/metrics` link takes 40 seconds to load as it carries out a speedtest
- You might get an error `Limit of concurrent requests reached (1), try again later.` this means a speedtest is already running
- `/health` link shows you if it can reach the internet

**Blackbox Exporter**
- Standard usage there is no need to visit this
- Access via your browser at [http://localhost:9115](http://localhost:9115)
- Recent probes table shows you past ping test details

## 📖 Extras
### Running versioned images

If you would like more control over which versions of each image to run please visit: [Moving to versioned releases](https://github.com/danopstech/starlink/blob/main/.docs/versioned_releases.md)

### Pushing to a cloud based Grafana account

As standard all data stays on your local machine in the `data` folder, we **do not** collect your dish metrics centrally. If you would like more information about pushing metrics into your own Grafana cloud account: [Pushing metrics to Grafana cloud](https://github.com/danopstech/starlink/blob/main/.docs/grafana_cloud.md)

## 📍 Roadmap
See the open [issues](https://github.com/danopstech/starlink/issues) for a list of proposed features (and known issues).

## 🖋️ License
[GPL-3.0 License](https://github.com/danopstech/starlink/blob/main/LICENSE)

## 😊 Author
This project was created in 2021 by [Dan Willcocks](https://github.com/dwillcocks).

## 👎 Troubleshooting
Some troubleshooting tips coming soon, until then raise an [issue](https://github.com/danopstech/starlink/issues/new?assignees=dwillcocks&labels=bug&template=bug_report.md&title=).

