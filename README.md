# NYERIUM The Cryptocurrency of Tomorrow

[![Build Status](https://travis-ci.org/nyerium-core/nyerium.svg?branch=master)](https://travis-ci.org/nyerium-core/nyerium) [![GitHub version](https://badge.fury.io/gh/nyerium-core%2Fnyerium.svg)](https://badge.fury.io/gh/nyerium-core%2Fnyerium)


## Nyerium Core integration/staging repository

Nyerium is an open source crypto-currency focused on fast private transactions with low transaction fees.  It utilizes a custom Proof of Stake protocol for securing its network and uses an innovative variable seesaw reward mechanism that dynamically balances 90% of its block reward size between masternodes, 10% for staking nodes, and 10% dedicated for budget proposals. Nyerium aims to achieve a decentralized sustainable crypto currency with near instant full-time private transactions, fair governance and community participation.
Key functionalities:
- Anonymized transactions using the [_Zerocoin Protocol_](http://www.nyerium.org/znye).
- Fast transactions featuring guaranteed zero confirmation transactions, we call it _SwiftX_.
- Decentralized blockchain voting utilizing Masternode technology to form a DAO. The blockchain will distribute monthly treasury funds based on successful proposals submitted by the community and voted on by the DAO.

More information at [nyerium.org](http://www.nyerium.org) Visit our ANN thread at [BitcoinTalk](https://bitcointalk.org/index.php?topic=4262979)

### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Max Coin Supply (PoW Phase)</td><td>1,600,000 NYEX</td></tr>
<tr><td>Max Coin Supply (PoS Phase)</td><td>120,000,000</td></tr>
<tr><td>Premine</td><td>10,000,000 NYEX*</td></tr>
</table>

### Reward Distribution

<table>
<th colspan=4>Genesis Block</th>
<tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr>
<tr><td>1</td><td>10,000,000 NYEX</td><td>Initial Pre-mine</td></tr>
</table>

### PoW Rewards Breakdown

<table>
<th>Block Height</th><th>Masternodes</th><th>Miner</th><th>Budget</th>
<tr><td>2-8000</td><td>80% (160 NYEX)</td><td>20% (40 NYEX)</td><td>N/A</td></tr>
</table>

### PoS Rewards Breakdown

<table>
<tr>	<td>Year</td>	<td>Month</td>	<td>Days</td>	<td>Block Start</td>	<td>Block End</td>	<td>Number of blocks</td>	<td>Total Reward</td>	<td>Coins Emitted</td>	<td>Running Sum</td>	<td>% MN Reward</td>	<td>% Staking Reward</td>	<td>% Governance</td>	</tr>
<tr><td>1</td><td>0</td><td>14</td><td>8002</td><td>20000</td><td>11999</td><td>250</td><td>2999750</td><td>4599750</td><td>85</td><td>15</td><td>0</td></tr>
<tr><td>1</td><td>1</td><td>30</td><td>20001</td><td>43200</td><td>23200</td><td>100</td><td>2320000</td><td>6919750</td><td>80</td><td>20</td><td>0</td></tr>
<tr><td>1</td><td>2</td><td>60</td><td>43201</td><td>86400</td><td>43200</td><td>50</td><td>2160000</td><td>9079750</td><td>90</td><td>10</td><td>0</td></tr>
<tr><td>1</td><td>2</td><td>69</td><td>86401</td><td>100000</td><td>13600</td><td>60</td><td>816000</td><td>9895750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1</td><td>3</td><td>90</td><td>100001</td><td>129600</td><td>29600</td><td>40</td><td>1184000</td><td>11079750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1</td><td>4</td><td>120</td><td>129601</td><td>172800</td><td>43200</td><td>30</td><td>1296000</td><td>12375750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1</td><td>5</td><td>150</td><td>172801</td><td>216000</td><td>43200</td><td>20</td><td>864000</td><td>13239750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1</td><td>6</td><td>180</td><td>216001</td><td>259200</td><td>43200</td><td>15</td><td>648000</td><td>13887750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1</td><td>7</td><td>210</td><td>259201</td><td>302400</td><td>43200</td><td>10</td><td>432000</td><td>14319750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1</td><td>8</td><td>240</td><td>302401</td><td>518400</td><td>216000</td><td>5</td><td>1080000</td><td>15399750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2</td><td>12</td><td>365</td><td>518401</td><td>525600</td><td>7200</td><td>100</td><td>720000</td><td>16119750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2</td><td>13</td><td>395</td><td>525601</td><td>568800</td><td>43200</td><td>40</td><td>1728000</td><td>17847750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2</td><td>14</td><td>425</td><td>568801</td><td>612000</td><td>43200</td><td>30</td><td>1296000</td><td>19143750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2</td><td>15</td><td>455</td><td>612001</td><td>655200</td><td>43200</td><td>20</td><td>864000</td><td>20007750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2</td><td>16</td><td>485</td><td>655201</td><td>698400</td><td>43200</td><td>10</td><td>432000</td><td>20439750</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2</td><td>17</td><td>515</td><td>698401</td><td>1049760</td><td>351360</td><td>5</td><td>1756800</td><td>22196550</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>3</td><td>24</td><td>736</td><td>1049761</td><td>1059760</td><td>10000</td><td>120</td><td>1200000</td><td>23396550</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>3</td><td>25</td><td>766</td><td>1059761</td><td>1102960</td><td>43200</td><td>30</td><td>1296000</td><td>24692550</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>3</td><td>26</td><td>796</td><td>1102961</td><td>1146160</td><td>43200</td><td>20</td><td>864000</td><td>25556550</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>3</td><td>27</td><td>826</td><td>1146161</td><td>1189360</td><td>43200</td><td>10</td><td>432000</td><td>25988550</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>3</td><td>28</td><td>856</td><td>1189361</td><td>1534960</td><td>345600</td><td>5</td><td>1728000</td><td>27716550</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>3</td><td>36</td><td>1095</td><td>1534961</td><td>1576720</td><td>41760</td><td>10</td><td>417600</td><td>28134150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>36</td><td>1102</td><td>1576721</td><td>1586720</td><td>10000</td><td>150</td><td>1500000</td><td>29634150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>37</td><td>1132</td><td>1586721</td><td>1629920</td><td>43200</td><td>25</td><td>1080000</td><td>30714150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>38</td><td>1162</td><td>1629921</td><td>1673120</td><td>43200</td><td>20</td><td>864000</td><td>31578150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>39</td><td>1192</td><td>1673121</td><td>1716320</td><td>43200</td><td>15</td><td>648000</td><td>32226150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>40</td><td>1222</td><td>1716321</td><td>1759520</td><td>43200</td><td>10</td><td>432000</td><td>32658150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>41</td><td>1252</td><td>1759521</td><td>2018720</td><td>259200</td><td>5</td><td>1296000</td><td>33954150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>47</td><td>1432</td><td>2018721</td><td>2061920</td><td>43200</td><td>10</td><td>432000</td><td>34386150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>4</td><td>48</td><td>1460</td><td>2061921</td><td>2102240</td><td>40320</td><td>15</td><td>604800</td><td>34990950</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>5</td><td>48</td><td>1468</td><td>2102241</td><td>2114240</td><td>12000</td><td>200</td><td>2400000</td><td>37390950</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>5</td><td>49</td><td>1472</td><td>2114241</td><td>2120240</td><td>6000</td><td>80</td><td>480000</td><td>37870950</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>5</td><td>50</td><td>1502</td><td>2120241</td><td>2163440</td><td>43200</td><td>40</td><td>1728000</td><td>39598950</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>5</td><td>51</td><td>1532</td><td>2163441</td><td>2206640</td><td>43200</td><td>20</td><td>864000</td><td>40462950</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>5</td><td>52</td><td>1562</td><td>2206641</td><td>2249840</td><td>43200</td><td>10</td><td>432000</td><td>40894950</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>5</td><td>53</td><td>1592</td><td>2249841</td><td>2627120</td><td>377280</td><td>5</td><td>1886400</td><td>42781350</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>6</td><td>60</td><td>1826</td><td>2627121</td><td>2630000</td><td>2880</td><td>220</td><td>633600</td><td>43414950</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>6</td><td>61</td><td>1856</td><td>2630001</td><td>2673200</td><td>43200</td><td>30</td><td>1296000</td><td>44710950</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>6</td><td>62</td><td>1886</td><td>2673201</td><td>2716400</td><td>43200</td><td>20</td><td>864000</td><td>45574950</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>6</td><td>63</td><td>1916</td><td>2716401</td><td>2759600</td><td>43200</td><td>10</td><td>432000</td><td>46006950</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>6</td><td>64</td><td>1946</td><td>2759601</td><td>3148400</td><td>388800</td><td>5</td><td>1944000</td><td>47950950</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>7--30</td><td>73--360</td><td>10804</td><td>3148401</td><td>15558210</td><td>12409810</td><td>5</td><td>62049050</td><td>110000000</td><td>50</td><td>40</td><td>10</td></tr>
</table>


### IMPORTANT NOTICE!

1. Reward is in NYEX not in BTC or USD. Get more information from the Team.
2. We are focus on long term goals for this project. Short term investors should be warry of  wide market fluctuations conditions
3. Don't put all your eggs in one basket and think of diversifying your portfolio. Don't invest all your life saving in crypto-currencies, unless you know and are willing to take the risk.
4. First time traders, should be particularly cautious and adopt basic crypto security (no help over Team Viewer) 
5. Don't fall for the FUD and the hype.
6. Reward indicated on Masternode Online and other masternode sites and purely indicative and should not be taken as investment advice.

The Nyerium Team
